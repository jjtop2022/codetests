using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int a, b, c;
            a = Convert.ToInt32(textBox1.Text);
            b = Convert.ToInt32(textBox2.Text);
            
            c = a + b;
            textBox3.Text = Convert.ToString(c);

            //button1.Enabled = true;

            //MessageBox.Show("test");
            ColorDialog dlg = new ColorDialog();
            dlg.ShowDialog();


        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {

            Graphics gg = this.CreateGraphics();
            
            gg.DrawLine(Pens.Red, 10, 10, 200, 10);
            gg.DrawLine(Pens.Red, 200, 10, 200, 200);
            gg.DrawLine(Pens.Red, 200, 200, 10, 200);
            gg.DrawLine(Pens.Red, 10, 200, 10, 10);
            gg.DrawLine(Pens.Blue, 10, 10, 200, 200);
            //////////////////////////////////////
            Rectangle r = new Rectangle(20,20,80,80);
            Rectangle r2 = new Rectangle(30, 30, 60, 60);
            Rectangle r3 = new Rectangle(40, 40, 50, 50);
            gg.DrawRectangle(Pens.Blue, r);
            gg.FillRectangle(Brushes.Red, r2);
            //gg.FillRectangle(Brushes.Yellow, r3);

        }


    }
}
