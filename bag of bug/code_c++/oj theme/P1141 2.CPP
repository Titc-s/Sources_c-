 #include<iostream>
  #include<string>
  using namespace std;
  
  void change(string& a)
  {
      for (int i = 0; i < a.size(); i++)
      {
          if (a[i] >= 'A'&&a[i] <= 'U')
             a[i] += 5;
         else if (a[i] >= 'V'&&a[i] <= 'Z')
             a[i] = 'A' + a[i] - 'V';
     }
 }
 
 int main()
 {
     string start, message, end;
     while ((getline(cin, start)) && (start.compare("ENDOFINPUT")))
     {
         getline(cin,message);
         getline(cin, end);
         change(message);
         cout << message << endl;
     }
     system("pause");
     return 0;
 }