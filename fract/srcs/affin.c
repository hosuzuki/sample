        // マウスをクリックした位置の保持用  
        private PointF OldPoint;  
        // アフィン変換行列  
        private System.Drawing.Drawing2D.Matrix mat;  
  
  
        private void Form1_Resize(object sender, EventArgs e)  
        {  
            if (g != null)  
            {  
                mat = g.Transform;  
                g.Dispose();  
                g = null;  
            }  
  
 
            // マウスをクリックした位置の記録  
            OldPoint.X = e.X;  
            OldPoint.Y = e.Y;  
            // マウスダウンフラグ  
            MouseDownFlg = true;  
        }  
  
        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)  
        {  
            // マウスをクリックしながら移動中のとき  
            if (MouseDownFlg == true)  
            {  
                // 画像の移動  
                mat.Translate(e.X - OldPoint.X, e.Y - OldPoint.Y,   
                    System.Drawing.Drawing2D.MatrixOrder.Append);  
                // 画像の描画  
                DrawImage();  
  
                // ポインタ位置の保持  
                OldPoint.X = e.X;  
                OldPoint.Y = e.Y;  
            }  
        }  
  
          // マウスホイールイベント  
        private void pictureBox1_MouseWheel(object sender, MouseEventArgs e)  
        {  
            // ポインタの位置→原点へ移動  
            mat.Translate(-e.X, -e.Y,   
                System.Drawing.Drawing2D.MatrixOrder.Append);  
            if (e.Delta > 0)  
            {  
                // 拡大  
                if (mat.Elements[0] < 100)  // X方向の倍率を代表してチェック  
                {  
                    mat.Scale(1.5f, 1.5f,   
                        System.Drawing.Drawing2D.MatrixOrder.Append);  
                }  
            }  
            else  
            {  
                // 縮小  
                if (mat.Elements[0] > 0.01)  // X方向の倍率を代表してチェック  
                {  
                    mat.Scale(1.0f / 1.5f, 1.0f / 1.5f,   
                        System.Drawing.Drawing2D.MatrixOrder.Append);  
                }  
            }  
            // 原点→ポインタの位置へ移動(元の位置へ戻す)  
            mat.Translate(e.X, e.Y,   
                System.Drawing.Drawing2D.MatrixOrder.Append);  
            // 画像の描画  
            DrawImage();  
        }  
  
    }  
}  
