using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Image_Gallery_Application
{
    public partial class TagForm : Form
    {
        public TagForm()
        {
            InitializeComponent();
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            var mainForm = new MainForm();
            if (tbTag.Text == "")
            {
                MessageBox.Show("Please enter a tag.");
            }
            else
            {
                this.Close();
            }
        }
    }
}
