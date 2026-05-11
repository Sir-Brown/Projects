using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Permissions;
using System.Text;
using System.Threading.Tasks;

namespace Email_Address_Book
{
    internal class PersonEntry
    {
        // Fields / Properties
        public string Name { get; set; }
        public string Email { get; set; }
        public string Phonenumber { get; set; }

        // Constructors
        public PersonEntry(string name, string email, string phonenumber)
        {
            Name = name;
            Email = email;
            Phonenumber = phonenumber;
        }
    }
}
