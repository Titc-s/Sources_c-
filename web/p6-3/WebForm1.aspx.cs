using System;
using System.Data;
using System.Data.SqlClient;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace p6_3
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            SqlConnection con = new SqlConnection();
            con.ConnectionString = "server = (local); uid = sa; pwd = 123; database = ASP;";
            string sql = "select a.student_id,student_name,student_department,Course_name,Grade from Student a,Course b,Stucourse c ";
            sql = sql + " where a.student_id = c.student_id and b.Course_id = c.Couese_id";
            SqlDataAdapter dap = new SqlDataAdapter(sql, con);
            DataSet ds = new DataSet();
            dap.Fill(ds);
            GridView1.DataSource = ds.Tables[0].DefaultView;
            GridView1.DataBind();
            con.Close();
        }
    }
}
