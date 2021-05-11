#include<bits/stdc++.h>
using namespace std;
class Student
{
    public :
        Student();
        Student(string, string );// 带参构造
        Student(int);
        ~Student();
        void ShowInfo();
        string GetName() { return m_name; }
        void SetName(string val) { m_name = val; }
        string Getdesc() { return m_desc; }
        void Setdesc(string val){m_desc= val;}
        int Getage() { return m_age; }
        void Setage(int val)
         {if (val < 0) m_age = 18;

         else          m_age = val;
        
          }
          void InitScores(); //初始化学生成绩数据，默认分配一个元素空间
          void AddScore(float); //向score中添加分数
          Student &GetSuperScholar(Student & ohterStu);
          float GetTotal();

      protected:

      private:
          string m_name;
          string m_desc;
          int m_age;
          int scoreCount; // 学生成绩个数
          float *scores;
};
Student::Student()
{
    cout << "默认构造" << endl;
}
Student:: Student(int age)
{
    Setage(age);
    cout << "带参年龄" << endl;
    InitScores();
}
Student::Student(string name,string desc):m_name(name),m_desc(desc)
{
    
    cout << "带参比u比u" << endl;
    InitScores();
}
float Student::GetTotal()
{
    float sum = 0;
    for (int i = 0; i < scoreCount - 1;i++){
        sum += scores[i];

    }
    return sum;
}
 void Student::InitScores()
 {
     this->scores = new float[1];
     this->scoreCount = 1;

 }
 void Student::AddScore(float score)
 {
     this->scores[this->scoreCount - 1] = score;
     float *newScores = new float[scoreCount + 1];
     float *oldScores = scores;
     memcpy(newScores, scores, sizeof(float) * scoreCount);
     scoreCount++;
     scores = newScores;
     delete oldScores;
 }
void Student:: ShowInfo()
{
    cout << m_desc << m_name << endl;
    for (int i = 0; i < scoreCount;i++){
        cout << this->scores[i] << "\t";

    }
    cout << endl;
}
Student& Student::GetSuperScholar(Student& otherStu) 
{
    if(this->GetTotal()>otherStu.GetTotal()){
        return *this;

    }else{
        return otherStu;
    }
    // 计算两个学生总分
}
Student::~Student()
{
    cout << m_name << "释放" << endl;
    delete this->scores;
}
int main()
{
  /*  int num;
    Student stu1;
    Student stu2("马化腾", "普通家庭");
   // Student stu3(18);
    //Student stu4 = 50;
    stu2.ShowInfo();
    Student *stu5 = new Student("刘强东","不知妻美");
    stu5->ShowInfo();
    */
    Student *ptrStu1 = new Student("迪丽热巴", "微胖女孩");
    ptrStu1->AddScore(78.9f);
    ptrStu1->AddScore(88.9f);
    ptrStu1->AddScore(98.9f);
    ptrStu1->AddScore(108.9f);
    ptrStu1->AddScore(298.9f);
    
    ptrStu1->ShowInfo();

    Student stu2 ("刘强东", "不爱美人");
    stu2.AddScore(85);
    stu2.AddScore(75);
    stu2.AddScore(65);
    stu2.AddScore(55);
    stu2.AddScore(45);

    Student& scholar1 = stu2.GetSuperScholar(*ptrStu1);
    Student& scholar2 = ptrStu1->GetSuperScholar(stu2);

    cout << "学霸是：" << scholar1.GetName() << "\t" << scholar2.GetName() << endl;

    delete ptrStu1;

    return 0;
}
