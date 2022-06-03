using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace chat
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void Application_Start(Object sender, EventArgs e)
        { //在应用程序启动时初始化聊天内容
            Application["chatcontent"] = "<h2>欢迎来到聊天室......</h2>";
        }

    }
}