using System;

namespace code_c_
{
    class Program
    {
        static void Main(string[] args)
        {
            test01 te = new test01();
            string str = te.Hello();
            Console.WriteLine("Hello World!" + str);
        }
    }
}
