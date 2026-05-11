using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Net.Mime.MediaTypeNames;

namespace Email_Address_Book
{
    public partial class PersonInformation : Form
    {
        public PersonInformation()
        {
            InitializeComponent();
        }

        // Close the form
        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
