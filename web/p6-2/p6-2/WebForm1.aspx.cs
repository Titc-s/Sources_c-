using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace p6_2
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            SqlConnection con = new SqlConnection();
            con.ConnectionString = "server = (local);uid = sa;pwd =123;database = ASP;";
            SqlCommand cmd = new SqlCommand();
            cmd.CommandText = "select* from Student";
            cmd.Connection = con;
            con.Open();
            SqlDataReader rd;
            rd = cmd.ExecuteReader();
            GridView1.DataSource = rd;
            GridView1.DataBind();

        }
    }
}