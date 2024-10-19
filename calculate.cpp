#include<iostream>
#include "Parameter.h"
#include<cmath>
using namespace std;

struct Parameter pa;

float high(float s, float v, float angle)
{
    float z;
    float t = (float)((exp(pa.k * s) - 1) / (pa.k * v * cos(angle)));
    z = (float)(v * sin(angle) * t - GRAVITY * t * t / 2);
    return z;
}

float angle(float s, float z_0, float z, float v)
{
    float z_temp, z_actual, dz;
    float angle_pitch;
    int i = 1;
    z_temp = z_0;
    int u = 0;
    while (true)
    {

        angle_pitch = atan2(z_temp, s); // rad
        z_actual = high(s, v, angle_pitch);
        dz = z - z_actual;
        
        double degrees = angle_pitch * (180.0 / PI);
        cout << "��������" << i<<endl;
        cout << "����ʵ�ʸ߶�Ϊ"<<z_actual<<endl;
        cout <<"��׼�߶�Ϊ" << z_temp << endl;
        cout << "����Ϊ" << degrees<<"��" << endl;
        cout << "���Ϊ" << dz << endl;
        z_temp = z_temp + dz;
        i++;
        if (fabsf(dz) < 0.000001)
        {
            u++;
            if (u == 2)
            {
                cout << "\n";
                cout << "��������Ϊ��" << degrees<<"��";
                break;
            }
            
        }
        cout << "\n";
        
        
    }
    return angle_pitch;
}

int main()
{
    pa.x_target = 3;
    pa.y_target = 4;
    pa.z_target = 0.25;
    float s = 5;
    pa.z_0 = 0.2;
    pa.k = 0.077;
    pa.current_v = 17;
    angle(s, pa.z_0, pa.z_target, pa.current_v);
    
}