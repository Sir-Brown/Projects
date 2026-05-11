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

namespace Word_Frequency_Application
{
    public partial class WordFreuencyApp : Form
    {
        public WordFreuencyApp()
        {
            InitializeComponent();
        }

        // Create the dictionaries (maybe try using public/private due to "best practice") Also "StringComparer.OrdinalIgnoreCase" is for the event the user enters something with capital letters
        private Dictionary<string, int> wordFrequency = new Dictionary<string, int>(StringComparer.OrdinalIgnoreCase);

        private void btnOpenFile_Click(object sender, EventArgs e)
        {
            try
            {
                // Opens the file
                DialogResult dialogResult = openFileDialog.ShowDialog();

                if (dialogResult == DialogResult.OK)
                {
                    // Clear previous results (Assumes user will check for different words in one session)
                    wordFrequency.Clear();

                    // Variables
                    String word, wordLower;
                    char[] separators = { ' ', '\n', '\r', ',', '.', '!', '?', ';', ':', '\t', '-', '(', ')', '[', ']', '"' };

                    // Utilize the "using()" method rather than regular open and reader.Close() - experimenting
                    using (StreamReader reader = new StreamReader(openFileDialog.FileName))
                    {
                        // Read file into string - split the string into an array - send the elements to the dictionary
                        while (!reader.EndOfStream)
                        {
                            // Read a line of text into the string
                            word = reader.ReadLine();

                            // Skips empty lines or white spaces
                            if (string.IsNullOrWhiteSpace(word)) continue;

                            // Split string into an array
                            string[] words = word.Split(separators, StringSplitOptions.RemoveEmptyEntries);

                            // Read words into dictionary and note their frequency
                            foreach (string palabra in words)
                            {
                                // Sets words to lowercase so "The" & "the" are treated as the same word
                                wordLower = palabra.ToLower();

                                if (wordFrequency.ContainsKey(wordLower))
                                {
                                    wordFrequency[wordLower]++;
                                }
                                else
                                {
                                    wordFrequency.Add(wordLower, 1);
                                }
                            }
                        }
                    }

                    // Let user know the file has been read
                    MessageBox.Show($"The file has been loaded successfully. Found {wordFrequency.Count} unique words.");
                }
            }
            catch
            {
                MessageBox.Show("Error: File not found or couldn't be proccessed.");
            }
        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            // Variable
            int count = 0;

            // Checks if the word is in the dictionary
            if (wordFrequency.TryGetValue(txtWord.Text, out count))
            {
                lblWordFrequency.Text = $"The word \"{txtWord.Text}\" has appeared {count} times.";
            }
            else
            {
                lblWordFrequency.Text = "The word was not found in the file provided.";
            }
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            // Close the file
            this.Close();
        }
    }
}
