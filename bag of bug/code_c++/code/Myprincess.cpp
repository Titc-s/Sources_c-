#include<bits/stdc++.h>
using namespace std;
int main ()
{
    // 1、为父女取名字
    /** 父亲名 */
    string value_father_name;
    /** 女儿名 */
    string value_daughter_name;
    int  value_birth_month = 6 ; // 女儿生日-月份
    int  value_birth_date = 6 ; // 女儿生日-日期
    string value_daughter_constell;// 星座

    string constell_names[12][2] = {
        {"魔羯座", "水瓶座"},//1月
        {"水瓶座", "双鱼座"},//2月
        {"双鱼座", "白羊座"},//3月
        {"白羊座", "金牛座"},//4月
        {"金牛座", "双子座"},//5月
        {"双子座", "巨蟹座"},//6月
        {"巨蟹座", "狮子座"},//7月
        {"狮子座", "处女座"},//8月
        {"处女座", "天秤座"},//9月
        {"天秤座", "天蝎座"},//10月
        {"天蝎座", "射手座"},//11月
        {"射手座", "魔羯座"},//12月

    };
    cout << "父亲的姓名：";
    cin >> value_father_name;
    cout << "女儿的姓名：";
    cin >> value_daughter_name;
    cout << "女儿的而生日(MM DD)：";
    cin >> value_birth_month >> value_birth_date;


    /** 各月份跨星座信息*/
    int constell_dates[]{20, 19, 21, 20, 21, 22, 23, 23, 23, 24, 23, 22};

    value_daughter_constell = constell_names[value_birth_month - 1][value_birth_date / constell_dates[value_birth_month - 1]];
    // 2、为女儿录入信息（生日，星座
    cout << "女儿的信息：";
    cout << "姓名：" << value_daughter_name << endl;
    cout << "生日：1659-" << value_birth_month << "-" << value_birth_date << endl;
    cout << "星座：" << value_daughter_constell << endl;

    // 根据女儿的星座，设置游戏基本参数（体力、智力、魅力、道德、气质
    // 3、开始游戏大循环
    //4、 根据各项参数，判定游戏结果

    return 0;
}