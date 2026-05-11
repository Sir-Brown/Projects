using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Drink_Machine_App
{
    public partial class DrinkMachineApp: Form
    {
        public DrinkMachineApp()
        {
            InitializeComponent();
        }

        public struct Soda
        {
            public string name;
            public double cost;
            public int amount;
        }

        Soda[] sodas = new Soda[5];
        double totalSales = 0.00;

        private void DrinkMachineApp_Load(object sender, EventArgs e)
        {
            sodas[0].name = "Coca Cola";
            sodas[0].cost = 1.00;

            sodas[1].name = "Root Bear";
            sodas[1].cost = 1.00;

            sodas[2].name = "Lemon Lime";
            sodas[2].cost = 1.00;

            sodas[3].name = "Grape Soda";
            sodas[3].cost = 1.50;

            sodas[4].name = "Cream Soda";
            sodas[4].cost = 1.50;

            for (int i = 0; i < 5; i++)
            {
                sodas[i].amount = 20;
                totalSales = 0.00;
            }
        }

        private void pbCola_Click(object sender, EventArgs e)
        {
            sodas[0].amount--;
            totalSales += sodas[0].cost;
            lblCola.Text = sodas[0].amount.ToString();
            lblTotalSales.Text = totalSales.ToString("C");
        }

        private void pbRoot_Click(object sender, EventArgs e)
        {
            sodas[1].amount--;
            totalSales += sodas[1].cost;
            lblRoot.Text = sodas[1].amount.ToString();
            lblTotalSales.Text = totalSales.ToString("C");
        }

        private void pbLemon_Click(object sender, EventArgs e)
        {
            sodas[2].amount--;
            totalSales += sodas[2].cost;
            lblLemon.Text = sodas[2].amount.ToString();
            lblTotalSales.Text = totalSales.ToString("C");
        }

        private void pbGrape_Click(object sender, EventArgs e)
        {
            sodas[3].amount--;
            totalSales += sodas[3].cost;
            lblGrape.Text = sodas[3].amount.ToString();
            lblTotalSales.Text = totalSales.ToString("C");
        }

        private void pbCream_Click(object sender, EventArgs e)
        {
            sodas[4].amount--;
            totalSales += sodas[4].cost;
            lblCream.Text = sodas[4].amount.ToString();
            lblTotalSales.Text = totalSales.ToString("C");
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
