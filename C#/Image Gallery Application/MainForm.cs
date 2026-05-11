using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Image_Gallery_Application
{
    public partial class MainForm : Form
    {
        string connectionString = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=\"C:\\Users\\jojob\\Source\\Repos\\Image-Gallery-Application2\\Image Gallery Application\\PhotoDatabase.mdf\";Integrated Security=True";
        public Dictionary<string, PhotoInfo> photoList = new Dictionary<string, PhotoInfo>();
        private List<Image> imageName = new List<Image>();
        private string[] fileType = { ".jpg", ".jpeg", ".png", ".gif", ".bmp" };

        public void getPhotoData()
        {
            DialogResult result = openFileDialog.ShowDialog();

            if (result == DialogResult.OK)
            {
                if (openFileDialog.FileName.ToLower().Contains(fileType[0]) ||
                    openFileDialog.FileName.ToLower().Contains(fileType[1]) ||
                    openFileDialog.FileName.ToLower().Contains(fileType[2]) ||
                    openFileDialog.FileName.ToLower().Contains(fileType[3]) ||
                    openFileDialog.FileName.ToLower().Contains(fileType[4]))
                {
                    try
                    {
                        string fileName = Path.GetFileName(openFileDialog.FileName);
                        string date = DateTime.Now.ToString("yyyy-MM-dd");
                        PhotoInfo photoInfo = new PhotoInfo(fileName, date);
                        photoList.Add(setTag(), photoInfo);
                        imageName.Add(Image.FromFile(openFileDialog.FileName));
                        lbImages.Items.Add(photoList.Last().Key);
                        toDataBase();
                    }
                    catch
                    {
                        MessageBox.Show("Error: Tag has already been used.");
                    }
                }
                else
                {
                    MessageBox.Show("Error: Please select a valid image file.");
                }
            }
            else
            {
                MessageBox.Show("Error: No file selected.");
            }
        }

        public void toDataBase()
        {
            SqlConnection connection;
            SqlCommand command;
            string query = "INSERT INTO PhotoData (PhotoID, PhotoTag, PhotoName, DateUploaded) VALUES (@ID, @Tag, @FileName, @Date)";


            using (connection = new SqlConnection(connectionString))
            using (command = new SqlCommand(query, connection))
            using (SqlDataAdapter adapter = new SqlDataAdapter(command))
            {
                command.Parameters.AddWithValue("@ID", photoList.Count);
                command.Parameters.AddWithValue("@Tag", photoList.Last().Key);
                command.Parameters.AddWithValue("@FileName", photoList.Last().Value.FileName);
                command.Parameters.AddWithValue("@Date", photoList.Last().Value.Date);
                try
                {
                    connection.Open();
                    command.ExecuteNonQuery();
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: " + ex.Message);
                }
            }
            connection.Close();
        }

        public void clearDataBase()
        {
            SqlConnection connection;
            SqlCommand command;

            connection  = new SqlConnection(connectionString);
            command = new SqlCommand("DELETE FROM PhotoData", connection);
            connection.Open();
            command.ExecuteNonQuery();
            connection.Close();
        }

        public string setTag()
        {
            var tagForm = new TagForm();
            tagForm.ShowDialog();
            return tagForm.tbTag.Text;
        }

        public MainForm()
        {
            InitializeComponent();
        }

        private void btnUpload_Click(object sender, EventArgs e)
        {
            getPhotoData();
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void lbImages_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                gbImageTitle.Text = lbImages.SelectedItem.ToString();
                pbImage.Image = imageName[lbImages.SelectedIndex];
            }
            catch
            {
                MessageBox.Show("Please select an image from the list.");
            }
        }

        private void btnView_Click(object sender, EventArgs e)
        {
            SqlConnection connection;
            SqlCommand command;
            int index = lbImages.SelectedIndex;
            var displayForm = new ImageInfo();

            connection = new SqlConnection(connectionString);
            command = new SqlCommand("SELECT * FROM PhotoData WHERE PhotoID = @ID", connection);

            command.Parameters.AddWithValue("@ID", (index + 1));
            connection.Open();
            using (SqlDataReader reader = command.ExecuteReader()) 
            {
                if (reader.Read())
                {
                    displayForm.lblTags.Text = reader["PhotoTag"].ToString();
                    displayForm.lblDate.Text = reader["DateUploaded"].ToString();
                    displayForm.lblFileName.Text = reader["PhotoName"].ToString();
                }
                connection.Close();
            }
            displayForm.ShowDialog();
        }

        private void btnOrganize_Click(object sender, EventArgs e)
        {
            object selectedItem = lbImages.SelectedItem;
            int index = lbImages.SelectedIndex;

            string[] tags = new string[lbImages.Items.Count];
            lbImages.Items.CopyTo(tags, 0);
            Array.Sort(tags, StringComparer.OrdinalIgnoreCase);

            List<Image> sortedImages = new List<Image>();
            foreach (string tag in tags)
            {
                int originalIndex = lbImages.Items.IndexOf(tag);
                sortedImages.Add(imageName[originalIndex]);
            }

            lbImages.BeginUpdate();
            try
            {
                lbImages.Items.Clear();
                lbImages.Items.AddRange(tags);
                imageName = sortedImages;

                if (selectedItem != null && lbImages.Items.Contains(selectedItem))
                {
                    lbImages.SelectedItem = selectedItem;
                    pbImage.Image = imageName[lbImages.SelectedIndex];
                }
            }
            finally
            {
                lbImages.EndUpdate();
            }
        }

        private void btnDataBase_Click(object sender, EventArgs e)
        {
           
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            clearDataBase();
        }
    }
}
