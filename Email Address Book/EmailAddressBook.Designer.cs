namespace Email_Address_Book
{
    partial class EmailAddressBookApp
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.lblTitle = new System.Windows.Forms.Label();
            this.lstPersons = new System.Windows.Forms.ListBox();
            this.btnExit = new System.Windows.Forms.Button();
            this.lblInstructuctions = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // lblTitle
            // 
            this.lblTitle.AutoSize = true;
            this.lblTitle.Font = new System.Drawing.Font("Mongolian Baiti", 19.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTitle.Location = new System.Drawing.Point(296, 91);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(298, 36);
            this.lblTitle.TabIndex = 0;
            this.lblTitle.Text = "Email Address Book";
            // 
            // lstPersons
            // 
            this.lstPersons.Font = new System.Drawing.Font("Mongolian Baiti", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lstPersons.FormattingEnabled = true;
            this.lstPersons.ItemHeight = 29;
            this.lstPersons.Location = new System.Drawing.Point(325, 295);
            this.lstPersons.Name = "lstPersons";
            this.lstPersons.Size = new System.Drawing.Size(241, 178);
            this.lstPersons.TabIndex = 2;
            this.lstPersons.SelectedIndexChanged += new System.EventHandler(this.lstPersons_SelectedIndexChanged);
            // 
            // btnExit
            // 
            this.btnExit.Font = new System.Drawing.Font("Mongolian Baiti", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnExit.Location = new System.Drawing.Point(399, 526);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(92, 49);
            this.btnExit.TabIndex = 3;
            this.btnExit.Text = "Exit";
            this.btnExit.UseVisualStyleBackColor = true;
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // lblInstructuctions
            // 
            this.lblInstructuctions.AutoSize = true;
            this.lblInstructuctions.Font = new System.Drawing.Font("Mongolian Baiti", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblInstructuctions.Location = new System.Drawing.Point(113, 192);
            this.lblInstructuctions.Name = "lblInstructuctions";
            this.lblInstructuctions.Size = new System.Drawing.Size(665, 30);
            this.lblInstructuctions.TabIndex = 4;
            this.lblInstructuctions.Text = "Please select a name from the list below to see their email:";
            // 
            // EmailAddressBookApp
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(923, 793);
            this.Controls.Add(this.lblInstructuctions);
            this.Controls.Add(this.btnExit);
            this.Controls.Add(this.lstPersons);
            this.Controls.Add(this.lblTitle);
            this.Name = "EmailAddressBookApp";
            this.Text = "Email Address Book";
            this.Load += new System.EventHandler(this.EmailAddressBookApp_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.ListBox lstPersons;
        private System.Windows.Forms.Button btnExit;
        private System.Windows.Forms.Label lblInstructuctions;
    }
}

