namespace game_hangman
{
    partial class Form1
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.pbHead = new System.Windows.Forms.PictureBox();
            this.pbTorso = new System.Windows.Forms.PictureBox();
            this.pbRightArm = new System.Windows.Forms.PictureBox();
            this.pbLeftArm = new System.Windows.Forms.PictureBox();
            this.pbRightLeg = new System.Windows.Forms.PictureBox();
            this.pbLeftLeg = new System.Windows.Forms.PictureBox();
            this.pbHanger = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.pbHead)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbTorso)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbRightArm)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbLeftArm)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbRightLeg)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbLeftLeg)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbHanger)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 83);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "label1";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 225);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "label2";
            // 
            // pbHead
            // 
            this.pbHead.Enabled = false;
            this.pbHead.Location = new System.Drawing.Point(388, 46);
            this.pbHead.Name = "pbHead";
            this.pbHead.Size = new System.Drawing.Size(48, 50);
            this.pbHead.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbHead.TabIndex = 2;
            this.pbHead.TabStop = false;
            // 
            // pbTorso
            // 
            this.pbTorso.Enabled = false;
            this.pbTorso.Location = new System.Drawing.Point(388, 102);
            this.pbTorso.Name = "pbTorso";
            this.pbTorso.Size = new System.Drawing.Size(48, 89);
            this.pbTorso.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbTorso.TabIndex = 2;
            this.pbTorso.TabStop = false;
            // 
            // pbRightArm
            // 
            this.pbRightArm.Enabled = false;
            this.pbRightArm.Location = new System.Drawing.Point(334, 102);
            this.pbRightArm.Name = "pbRightArm";
            this.pbRightArm.Size = new System.Drawing.Size(48, 50);
            this.pbRightArm.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbRightArm.TabIndex = 2;
            this.pbRightArm.TabStop = false;
            // 
            // pbLeftArm
            // 
            this.pbLeftArm.Enabled = false;
            this.pbLeftArm.Location = new System.Drawing.Point(442, 102);
            this.pbLeftArm.Name = "pbLeftArm";
            this.pbLeftArm.Size = new System.Drawing.Size(48, 50);
            this.pbLeftArm.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbLeftArm.TabIndex = 2;
            this.pbLeftArm.TabStop = false;
            // 
            // pbRightLeg
            // 
            this.pbRightLeg.Enabled = false;
            this.pbRightLeg.Location = new System.Drawing.Point(334, 188);
            this.pbRightLeg.Name = "pbRightLeg";
            this.pbRightLeg.Size = new System.Drawing.Size(48, 50);
            this.pbRightLeg.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbRightLeg.TabIndex = 2;
            this.pbRightLeg.TabStop = false;
            // 
            // pbLeftLeg
            // 
            this.pbLeftLeg.Enabled = false;
            this.pbLeftLeg.Location = new System.Drawing.Point(442, 188);
            this.pbLeftLeg.Name = "pbLeftLeg";
            this.pbLeftLeg.Size = new System.Drawing.Size(48, 50);
            this.pbLeftLeg.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbLeftLeg.TabIndex = 2;
            this.pbLeftLeg.TabStop = false;
            // 
            // pbHanger
            // 
            this.pbHanger.Location = new System.Drawing.Point(388, 12);
            this.pbHanger.Name = "pbHanger";
            this.pbHanger.Size = new System.Drawing.Size(153, 303);
            this.pbHanger.TabIndex = 3;
            this.pbHanger.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(553, 378);
            this.Controls.Add(this.pbLeftLeg);
            this.Controls.Add(this.pbLeftArm);
            this.Controls.Add(this.pbRightLeg);
            this.Controls.Add(this.pbRightArm);
            this.Controls.Add(this.pbTorso);
            this.Controls.Add(this.pbHead);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.pbHanger);
            this.Name = "Form1";
            this.Text = "Hangman!";
            ((System.ComponentModel.ISupportInitialize)(this.pbHead)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbTorso)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbRightArm)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbLeftArm)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbRightLeg)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbLeftLeg)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbHanger)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.PictureBox pbHead;
        private System.Windows.Forms.PictureBox pbTorso;
        private System.Windows.Forms.PictureBox pbRightArm;
        private System.Windows.Forms.PictureBox pbLeftArm;
        private System.Windows.Forms.PictureBox pbRightLeg;
        private System.Windows.Forms.PictureBox pbLeftLeg;
        private System.Windows.Forms.PictureBox pbHanger;
    }
}