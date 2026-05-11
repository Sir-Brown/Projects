using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Email_Address_Book
{
    public partial class EmailAddressBookApp : Form
    {
        public EmailAddressBookApp()
        {
            InitializeComponent();
        }

        // Create lists to hold the information
        private List<PersonEntry> persons = new List<PersonEntry>();

        // Create a function to load the file rather than implement the code in the onLoad
        private void LoadPersonas()
        {
            try
            {
                using (StreamReader reader = File.OpenText("PersonalEntry.txt"))
                {
                    while (!reader.EndOfStream)
                    {
                        string name = reader.ReadLine();
                        string email = reader.ReadLine();
                        string phonenumber = reader.ReadLine();

                        PersonEntry person = new PersonEntry(name, email, phonenumber);
                        persons.Add(person);
                        lstPersons.Items.Add(person.Name);
                    }
                }
            }
            catch
            {
                MessageBox.Show("Error: Could not load file.");
            }
        }

        // Calls the load function upon loading
        private void EmailAddressBookApp_Load(object sender, EventArgs e)
        {
            LoadPersonas();
        }

        // Calls message form to display results
        private void lstPersons_SelectedIndexChanged(object sender, EventArgs e)
        {
            // Create a new instance of the PersonInformation class
            var form = new PersonInformation();

            // Displays additional information once the user has selected a name
            if (lstPersons.SelectedIndex >= 0 && lstPersons.SelectedIndex < persons.Count)
            {
                PersonEntry selectedPerson = persons[lstPersons.SelectedIndex];

                form.NameLabel.Text = selectedPerson.Name;
                form.EmailLabel.Text = selectedPerson.Email;
                form.PhoneNumberLabel.Text = selectedPerson.Phonenumber;
            }

            // Display the form
            form.ShowDialog();           
        }

        // Exits the app
        private void btnExit_Click(object sender, EventArgs e)
        {
            // Close the file
            this.Close();
        }
    }
}
