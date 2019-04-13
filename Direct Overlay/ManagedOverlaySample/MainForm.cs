using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using ManagedOverlayLib;

namespace ManagedOverlaySample
{
    public partial class MainForm : Form
    {
        OverlayManager overlayManager_ = new OverlayManager();
        Bitmap image32_ = null;
        Bitmap image24_ = null;
        Bitmap image565_ = null;
        Bitmap image555_ = null;
        int imageToBlit = 0;

        public MainForm()
        {
            InitializeComponent();
        }

        private void visibleRadio_CheckedChanged(object sender, EventArgs e)
        {
            if(!overlayManager_.IsInitialized)
                overlayManager_.Reset(this.Width, this.Height);

            widthText.Text = this.Width.ToString();
            heightText.Text = this.Height.ToString();
            formatText.Text = overlayManager_.PixelFormat.ToString();

            overlayManager_.ShowOverlay();
            overlayManager_.RenderingCallback = new RenderingDelegate(RenderingCallback);

            timer_.Start();
        }

        private void hiddenRadio_CheckedChanged(object sender, EventArgs e)
        {
            if(overlayManager_.IsInitialized)
                overlayManager_.ShowOverlay(false);

            timer_.Stop();
        }

        private void timer__Tick(object sender, EventArgs e)
        {
            if(overlayManager_.IsInitialized && visibleRadio.Checked)
            {
                overlayManager_.Update();
            }
        }

        void RenderingCallback(IntPtr surface, IntPtr userData)
        {
            if (image24_ == null && image32_ == null && image565_ == null && 
                image555_ == null)
            {
                image24_ = new Bitmap(this.Width, this.Height,
                    System.Drawing.Imaging.PixelFormat.Format24bppRgb);

                Font font = new Font("Arial", 12);
                Brush brush = new SolidBrush(Color.White);
                using (Graphics g = Graphics.FromImage(image24_))
                {
                    g.FillEllipse(new SolidBrush(Color.Blue), 0, 0, this.Width, this.Height);
                    g.DrawString("24-bit RGB", font, brush, 0, 0);
                }

                image32_ = new Bitmap(this.Width, this.Height,
                    System.Drawing.Imaging.PixelFormat.Format32bppRgb);
                using (Graphics g = Graphics.FromImage(image32_))
                {
                    g.FillEllipse(new SolidBrush(Color.Blue), 0, 0, this.Width, this.Height);
                    g.DrawString("32-bit RGB", font, brush, 0, 0);
                }

                image555_ = new Bitmap(this.Width, this.Height,
                    System.Drawing.Imaging.PixelFormat.Format16bppRgb555);
                using (Graphics g = Graphics.FromImage(image555_))
                {
                    g.FillEllipse(new SolidBrush(Color.Blue), 0, 0, this.Width, this.Height);
                    g.DrawString("16-bit RGB 555", font, brush, 0, 0);
                }

                image565_ = new Bitmap(this.Width, this.Height,
                    System.Drawing.Imaging.PixelFormat.Format16bppRgb565);
                using (Graphics g = Graphics.FromImage(image565_))
                {
                    g.FillEllipse(new SolidBrush(Color.Blue), 0, 0, this.Width, this.Height);
                    g.DrawString("16-bit RGB 565", font, brush, 0, 0);
                }
            }

            switch(imageToBlit)
            {
                case 0:
                    Blitter.Blit(surface, 0, 0, image32_, 0, 0);
                    break;

                case 1:
                    Blitter.Blit(surface, 0, 0, image24_, 0, 0);
                    break;

                case 2:
                    Blitter.Blit(surface, 0, 0, image565_, 0, 0);
                    break;

                case 3:
                    Blitter.Blit(surface, 0, 0, image555_, 0, 0);
                    break;
            }

            imageToBlit++;
            if (imageToBlit > 3)
                imageToBlit = 0;
        }

        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            overlayManager_.Dispose();
        }
    }
}