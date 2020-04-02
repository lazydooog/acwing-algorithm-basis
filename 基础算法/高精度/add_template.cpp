/*
 * @Description: 高精度加法模板
 * @Author: Xiaobin Ren
 * @Date: 2020-04-02 10:36:12
 * @LastEditTime: 2020-04-02 10:46:30
 */

/*
    用数组逆向来存数字，之所以逆向是因为如果要进位的话
    直接在答案数组的末尾push_back(1)就好了，但是如果顺序存储的话
    要把所有元素后移一位 成本太高

    本质原理： 手动模拟人工加法，但是过程是镜像反转之后的
    人工是从右往左进位，数组模拟从左往右进位
*/

//板子1
vector<int> add(vector<int> &a, vector<int> &b){
    vector<int> c;  //答案
    int t = 0;  //进位标记
    for(int i = 0; i< a.size() || i<b.size(); i++){
        if(i < a.size()) t+=a[i];
        if(i < b.size()) t+=b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    if(t) c.push_back(1);
    return c;
}


//板子2
// C = A + B, A >= 0, B >= 0
vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size()) return add(B, A);

    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i ++ )
    {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t) C.push_back(t);
    return C;
}
