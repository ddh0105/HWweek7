#include<iostream>

using namespace std;


//Su dung struct de luu du lieu cho so nguoi duoc sinh ra theo tung nam
struct danso{
    int year;
    int songuoisinh;
};

void swap(danso &a, danso &b){
    danso temp = a; 
    a = b;
    b = temp;
}

//sap xep lai theo thu tu so luong nguoi sinh tang dan
void sap_xep(danso ds[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n - i- 1; j++){
            if (ds[j].songuoisinh > ds[j+1].songuoisinh){
                swap(ds[j], ds[j+1]);
            }
        }
    }
}

//dem so nam co cung so nguoi sinh ra
void sonam(danso ds[], int n){
    bool da_xet[1000001] = {false};

    for (int i =0; i < n; i++){
        if (!da_xet[i]){
            int so_luong = ds[i].songuoisinh;
            cout << "\nVoi so luong sinh la "<<so_luong<<" co: ";
        
        for (int j = i; j < n; j++){
            if (ds[j].songuoisinh == so_luong){
                cout << ds[j].year<<" ";
                da_xet[j]=true;
            }
        }
        cout << endl;
        }
    }
}
//tim nam co so luong sinh nhieu nhat va it nhat
void max_min(danso ds[], int n, int &nam_max, int &nam_min){
    sap_xep(ds,n);//sap xep tang dan theo so luong sinh
    nam_min = ds[0].year;//nam co it nguoi duoc sinh ra nhat
    nam_max = ds[n-1].year;//nam co nhieu nguoi duoc sinh ra nhat
}

//viet chuong trinh chinh
int main(){
    int n;
    cout <<"Nhap so nam cam quan ly: ";
    cin >> n;

    danso ds[100000];

    for (int i = 0; i < n; i++){
        cin >> ds[i].year;
        cin >> ds[i].songuoisinh;
    }

    int lua_chon;
    cout <<"Chon yeu cau: \n";
    cout << "1. Hien thi cac so nam co cung so luong sinh\n";
    cout <<"2. Tim nam co so nguoi sinh ra nhieu nhat va it nhat\n";
    cout <<"3. Thuc hien ca 2 yeu cau tren\n";
    cout << "Nhap lua chon cua ban: \n";

    cin >> lua_chon;

    switch ( lua_chon)
    {
    case 1:{
        sonam(ds, n);
        break;
    }
    case 2:{
        int nam_max, nam_min;
        max_min(ds, n, nam_max, nam_min);
        cout << "Nam co nguoi sinh nhieu nhat la: "<<nam_max<<endl;
        cout << "Nam co nguoi sinh it nhat la: "<<nam_min<<endl;
        break;
    }
    case 3:{
        sonam(ds, n);

        int nam_max, nam_min;
        max_min(ds, n, nam_max, nam_min);
        cout << "Nam co nguoi sinh nhieu nhat la: "<<nam_max<<endl;
        cout << "Nam co nguoi sinh it nhat la: "<<nam_min<<endl;
        break;
        
    }
    default:
        cout <<"Lua chon khong hop le!"<<endl;
    }

    return 0;

}