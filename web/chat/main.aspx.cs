using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace chat
{
    public partial class main : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            //把Application中的聊天信息读出来显示在页面中
            this.labMessage.Text = (string)Application["chatcontent"];
        }
    }
}