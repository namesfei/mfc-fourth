
#include<iostream>
using namespace std;
struct sta_shipdata 
{
	char MMSI[9];
	const char* name;
	char number[4];
	float length;	//��λ����
	float width;	//��λ����
	float draft;
	float displacement; //��λ����

};
struct zuobiao
{
	double x;
	double y;
};
struct dy_shipdata
{
	zuobiao ship_profile[5];
	double speed;	// ǧ��/Сʱ
	double course;	// ����Ϊ0��
	double latitude; //�����ϸ�
	double longitude;//��������
};

class Ship 
{
public:
	Ship();
	Ship(sta_shipdata stdat);
	~Ship();
	void set_position(double latu, double lotu);
	void set_speed_course(double _speed, double _course);
	void set_ship_profile();
	void dy_set_profile();
	void set_ship_profile_byscale(double scale);
	double ca_fangwei(double lati,double longi);
	double ca_juli(double lati, double longi);
	void showmessage();
	sta_shipdata* outsm();
	dy_shipdata* outdm();

private:
	sta_shipdata* pm_sta_shipdata;
	dy_shipdata* pm_dy_shipdata;
	//zuobiao ship_profile[5];
	//double speed;	// ǧ��/Сʱ
	//double course;	// ����Ϊ0��
	//double latitude; //�����ϸ�
	//double longitude;//��������
};
