using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Image_Gallery_Application
{
    public class PhotoInfo
    {
        public PhotoInfo(string fileName, string date)
        {
            FileName = fileName;
            Date = date;
        }

        public PhotoInfo()
        {
            FileName = "None";
            Date = "None";
        }

        public string FileName { get; set; }
        public string Date { get; set; }
    }
}
