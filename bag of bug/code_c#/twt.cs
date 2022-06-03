using System;
namespace code_c_
{
    class ToSubstring
    {
        public static void Main(string[] args)
        {
            MyString mystring = new MyString();

            //IndexOf
            Console.WriteLine("IndexOf函数测试：");
            Console.WriteLine("输入一组字符串");
            string str1 = Console.ReadLine();
            Console.WriteLine("输入需要定位的字符");
            char key1 = Convert.ToChar(Console.ReadLine());
            int res1 = mystring.IndexOf(str1, key1);
            Console.WriteLine("结果是：");
            Console.WriteLine(res1);

            //Compare
            Console.WriteLine("Compare函数测试：");
            Console.WriteLine("输入一组字符串");
            string str2 = Console.ReadLine();
            Console.WriteLine("再输入一组字符串");
            string str3 = Console.ReadLine();
            int res2 = mystring.Compare(str2, str3);
            Console.WriteLine("结果是：");
            Console.WriteLine(res2);

            //Length
            Console.WriteLine("Length函数测试：");
            Console.WriteLine("输入一组字符串");
            string str4 = Console.ReadLine();
            int res3 = mystring.Length(str4);
            Console.WriteLine("结果是：");
            Console.WriteLine(res3);

            //Substring
            Console.WriteLine("Substring函数测试：");
            Console.WriteLine("输入一组字符串");
            string str5 = Console.ReadLine();
            Console.WriteLine("输入起始位置");
            int begin1 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("输入子串长度");
            int len1 = Convert.ToInt32(Console.ReadLine());
            string res4 = mystring.Substring(str5, begin1, len1);
            Console.WriteLine("结果是：");
            Console.WriteLine(res4);

            //Remove
            Console.WriteLine("Remove函数测试：");
            Console.WriteLine("输入一组字符串");
            string str6 = Console.ReadLine();
            Console.WriteLine("输入起始位置");
            int begin2 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("输入移除的长度");
            int len2 = Convert.ToInt32(Console.ReadLine());
            string res5 = mystring.Remove(str6, begin2, len2);
            Console.WriteLine("结果是：");
            Console.WriteLine(res5);

            //Insert
            Console.WriteLine("Insert函数测试：");
            Console.WriteLine("输入一组字符串");
            string str7 = Console.ReadLine();
            Console.WriteLine("输入起始位置");
            int begin3 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("输入要插入字符串");
            string str8 = Console.ReadLine();
            string res6 = mystring.Insert(str7, begin3, str8);
            Console.WriteLine("结果是：");
            Console.WriteLine(res6);

            //Replace
            Console.WriteLine("Replace函数测试：");
            Console.WriteLine("输入一组字符串");
            string str9 = Console.ReadLine();
            Console.WriteLine("输入要被替换的字符串");
            string str10 = Console.ReadLine();
            Console.WriteLine("输入要被插入的字符串");
            string str11 = Console.ReadLine();
            string res7 = mystring.Replace(str9, str10, str11);
            Console.WriteLine("结果是：");
            Console.WriteLine(res7);

            //ToLower
            Console.WriteLine("ToLower函数测试：");
            Console.WriteLine("输入一组字符串");
            string str12 = Console.ReadLine();
            string res8 = mystring.ToLower(str12);
            Console.WriteLine("结果是：");
            Console.WriteLine(res8);

            //ToUpper
            Console.WriteLine("ToUpper函数测试：");
            Console.WriteLine("输入一组字符串");
            string str13 = Console.ReadLine();
            string res9 = mystring.ToUpper(str13);
            Console.WriteLine("结果是：");
            Console.WriteLine(res9);

            //Trim
            Console.WriteLine("Trim函数测试：");
            Console.WriteLine("输入一组字符串");
            string str14 = Console.ReadLine();
            string res10 = mystring.Trim(str14);
            Console.WriteLine("结果是：");
            Console.WriteLine(res10);
        }
    }

    class MyString
    {
        //IndexOf
        public int IndexOf(string str, char key)
        {
            for (int i = 0; i < str.Length; i++)
            {
                if (str[i] == key)
                {
                    return i;
                }
            }
            return -1;
        }

        //实现Compare函数
        public int Compare(string str1, string str2)
        {
            int len1 = str1.Length;
            int len2 = str2.Length;
            int len = len1 > len2 ? len2 : len1;
            for (int i = 0; i < len; i++)
            {
                if (str1[i] > str1[i])
                {
                    return 1;
                }
                if (str1[i] < str2[i])
                {
                    return -1;
                }
            }
            if (len1 == len2)
            {
                return 0;
            }
            else
            {
                if (len1 > len2) { return 1; }
            }
            return -1;
        }

        //实现Length函数
        public int Length(string str)
        {
            int len = 0;
            foreach (int i in str)
            {
                len++;
            }
            return len;
        }

        //实现Substring函数
        public string Substring(string str, int begin, int len)
        {
            int cnt = 0;
            char[] temp = new char[len];
            for (int i = begin; i < begin + len; i++)
            {
                temp[cnt++] = str[i];
            }
            string substr = new string(temp);
            return substr;
        }

        //实现Remove函数
        public string Remove(string str, int begin, int len)
        {
            int strlen = str.Length;
            char[] temp = new char[strlen];
            for (int i = begin + len; i < strlen; i++)
            {
                temp[i - len] = str[i];
            }
            for (int i = 0; i < begin; i++)
            {
                temp[i] = str[i];
            }
            string newString;
            newString = new string(temp);
            return newString;
        }

        //实现Insert函数
        public string Insert(string str, int begin, string str2)
        {
            int cnt = 0;
            int len = str2.Length;
            int len2 = str.Length;
            char[] temp = new char[len + len2];
            for (int i = 0; i < len2; i++)
            {
                temp[i] = str[i];
            }
            for (int i = begin; i < len2; i++)
            {
                temp[i + len] = str[i];
            }
            for (int i = 0; i < begin; i++)
            {
                temp[i] = str[i];
            }
            for (int i = begin; i < begin + len; i++)
            {
                temp[i] = str2[cnt++];
            }
            str = new string(temp);
            return str;
        }

        //实现Replace
        public string Replace(string str1, string str2, string str3)
        {
            //@TODO 用subString、compare函数找到字符串位置，返回位置
            int flag = 0;
            int len2 = str2.Length;
            int len1 = str1.Length;
            for (int i = 0; i <= len1 - len2; i++)
            {
                if (str1.Substring(i, len2).CompareTo(str2) == 0)
                {
                    flag = i; //本段程序只考虑主串中只含有一个目标字串
                }
            }

            //@TODO Remove字符串
            str1 = str1.Remove(flag, len2);

            //@TODO Insert字符串
            str1 = str1.Insert(flag, str3);

            return str1;

        }

        //实现ToLower函数
        public string ToLower(string str)
        {
            int len = str.Length;
            char[] temp = str.ToCharArray();
            for (int i = 0; i < len; i++)
            {
                if (temp[i] >= 'A' && temp[i] <= 'Z')
                {
                    temp[i] = Convert.ToChar(temp[i] - 'A' + 'a');
                }
            }
            str = new string(temp);
            return str;
        }

        //实现ToUpper函数
        public string ToUpper(string str)
        {
            int len = str.Length;
            char[] temp = str.ToCharArray();
            for (int i = 0; i < len; i++)
            {
                if (temp[i] >= 'a' && temp[i] <= 'z')
                {
                    temp[i] = Convert.ToChar(temp[i] - 32);
                }
            }
            str = new string(temp);
            return str;
        }

        //实现Trim函数
        public string Trim(string str)
        {
            int cnt = 0;
            int flag = 0;
            int flag0 = 0;
            for (int i = 0; i < str.Length; i++)
            {
                if (str[i] != ' ')
                {
                    flag0 = 1;
                    break;
                }
            }
            if (flag0 == 0)
            {
                string str1 = "字符串全部为空";
                return str1;
            }
            while (str[cnt] == ' ')
            {
                cnt++;
            }
            char[] temp = new char[str.Length - cnt];
            for (int i = cnt; i < str.Length; i++)
            {
                temp[flag++] = str[i];
            }

            //@TODO 去除最后的空格，自后往前，用while实现。
            int len = temp.Length;
            while (temp[len - 1] == ' ')
            {
                len--;
            }
            char[] temp2 = new char[len];
            for (int i = 0; i < len; i++)
            {
                temp2[i] = temp[i];
            }
            str = new string(temp2);
            return str;
        }
    }
}
