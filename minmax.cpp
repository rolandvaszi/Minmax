#include <iostream>
#include <windows.h>

using namespace std;

int* gepmax(int gepbabu, string* babuk, string tabla[4][4], int masodperc);
int jatekmin(string* babuk, string tabla[4][4]);
bool figyelo(string tabla[4][4]);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Nincs eleg bemeneti parameter!" << endl;
        return 0;
    }
    int melyseg = argv[1][1], masodperc = argv[1][2];
    string tabla[4][4];
    string babuk[17];
    babuk[1] = "FKMTi";
    babuk[2] = "FKMUi";
    babuk[3] = "FKATi";
    babuk[4] = "FKAUi";
    babuk[5] = "FHMTi";
    babuk[6] = "FHMUi";
    babuk[7] = "FHATi";
    babuk[8] = "FHAUi";
    babuk[9] = "BKMTi";
    babuk[10] = "BKMUi";
    babuk[11] = "BKATi";
    babuk[12] = "BKAUi";
    babuk[13] = "BHMTi";
    babuk[14] = "BHMUi";
    babuk[15] = "BHATi";
    babuk[16] = "BHAUi";
    string jatekos = "jatekos";
    int gepbabu;
    while (figyelo(tabla) == true)
    {
        int n, m, x;
        if (jatekos == "jatekos")
        {
            int jat = jatekmin(babuk, tabla);
            bool pozicios = false;
            while (pozicios != true) {
                cout << "az " << babuk[jat][0] << babuk[jat][1] << babuk[jat][2] << babuk[jat][3] << " babuval kell lepjen n m koordinatara:" << endl;
                cout << "n=";
                cin >> n;
                cout << "m=";
                cin >> m;
                if (n <= 4 && n >= 0 && m <= 4 && m >= 0)
                {
                    if (tabla[n - 1][m - 1].length() == 0)
                    {
                        pozicios = true;
                    }
                    else
                    {
                        cout << endl << "a pozicio foglalt" << endl;
                    }
                }
                else
                {
                    cout << endl << "nem megfelelo koordinatak" << endl;
                }
            }
            system("cls");
            babuk[jat][4] = 'a';
            tabla[n - 1][m - 1] = babuk[jat];
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (tabla[i][j].length() == 0)
                    {
                        cout << "----";
                    }
                    else
                    {
                        cout << tabla[i][j][0] << tabla[i][j][1] << tabla[i][j][2] << tabla[i][j][3];
                    }
                    cout << " ";
                }
                cout << endl;
            }
            cout << endl << "szabad babuk" << endl;
            for (int i = 1; i <= 16; ++i)
            {
                if (babuk[i][4] == 'i')
                {
                    cout << i << ". ";
                    for (int j = 0; j < 4; j++)
                    {
                        cout << babuk[i][j];
                    }
                }
                cout << endl;
            }
            bool babus = false;
            while (babus != true) {
                cout << endl << "adjon egy babut a gepnek:";
                cin >> gepbabu;
                if (babuk[gepbabu][4] == 'a')
                    cout << "ez a babu mar a tablan van" << endl;
                else
                    babus = true;
            }
            babuk[gepbabu][4] = 'a';
            jatekos = "gep";
        }
        else
        {
            int* poz = gepmax(gepbabu, babuk, tabla, masodperc);
            n = poz[0];
            m = poz[1];
            tabla[n][m] = babuk[gepbabu];
            cout << endl << endl << "a gep lep" << endl << endl;
            jatekos = "jatekos";
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (tabla[i][j].length() == 0)
                    {
                        cout << "----";
                    }
                    else
                    {
                        cout << tabla[i][j][0] << tabla[i][j][1] << tabla[i][j][2] << tabla[i][j][3];
                    }
                    cout << " ";
                }
                cout << endl;
            }
        }

    }
    return 0;
}
bool figyelo(string tabla[4][4])
{
    bool teli = true;
    for (int i = 0; i < 4; ++i)
    {
        bool soros[] = { true,true,true,true };
        bool figy1 = true;
        for (int j = 0; j < 3; j++)
        {
            if (tabla[i][j].length() == 0 || tabla[i][j + 1].length() == 0)
            {
                teli = false;
                figy1 = false;
            }
            if (tabla[i][j].length() != 0 && tabla[i][j + 1].length() != 0)
            {
                if (tabla[i][j][0] != tabla[i][j + 1][0])
                {
                    soros[0] = false;
                }
                if (tabla[i][j][1] != tabla[i][j + 1][1])
                {
                    soros[1] = false;
                }
                if (tabla[i][j][2] != tabla[i][j + 1][2])
                {
                    soros[2] = false;
                }
                if (tabla[i][j][3] != tabla[i][j + 1][3])
                {
                    soros[3] = false;
                }
            }
        }
        for (int x = 0; x < 4; x++)
        {
            if (soros[x] == true && figy1 == true)
                return false;
        }
    }

    for (int j = 0; j < 4; ++j)
    {
        bool oszlopos[] = { true,true,true,true };
        bool figy2 = true;
        for (int i = 0; i < 3; i++)
        {
            if (tabla[i][j].length() == 0 || tabla[i + 1][j].length() == 0)
            {
                teli = false;
                figy2 = false;
            }
            if (tabla[i][j].length() != 0 && tabla[i + 1][j].length() != 0)
            {
                if (tabla[i][j][0] != tabla[i + 1][j][0])
                {
                    oszlopos[0] = false;
                }
                if (tabla[i][j][1] != tabla[i + 1][j][1])
                {
                    oszlopos[1] = false;
                }
                if (tabla[i][j][2] != tabla[i + 1][j][2])
                {
                    oszlopos[2] = false;
                }
                if (tabla[i][j][3] != tabla[i + 1][j][3])
                {
                    oszlopos[3] = false;
                }
            }
        }
        for (int x = 0; x < 4; x++)
        {
            if (oszlopos[x] == true && figy2 == true)
                return false;
        }
    }
    if (teli == true)
        return false;
    bool foatlo[] = { true,true,true,true };
    bool figy3 = true;
    for (int i = 0; i < 3; ++i)
    {
        if (tabla[i][i].length() == 0 || tabla[i + 1][i + 1].length() == 0)
        {
            teli = false;
            figy3 = false;
        }
        if (tabla[i][i].length() != 0 && tabla[i + 1][i + 1].length() != 0)
        {
            if (tabla[i][i][0] != tabla[i + 1][i + 1][0])
            {
                foatlo[0] = false;
            }
            if (tabla[i][i][1] != tabla[i + 1][i + 1][1])
            {
                foatlo[1] = false;
            }
            if (tabla[i][i][2] != tabla[i + 1][i + 1][2])
            {
                foatlo[2] = false;
            }
            if (tabla[i][i][2] != tabla[i + 1][i + 1][2])
            {
                foatlo[3] = false;
            }
        }
    }
    for (int x = 0; x < 4; x++)
    {
        if (foatlo[x] == true && figy3 == true)
            return false;
    }
    bool mellekatlo[] = { true,true,true,true };
    bool figy4 = true;
    for (int i = 0; i < 3; ++i)
    {
        if (tabla[i][3 - i].length() == 0 || tabla[i + 1][3 - i + 1].length() == 0)
        {
            teli = false;
            figy4 = false;
        }
        if (tabla[i][3 - i].length() != 0 && tabla[i + 1][3 - i + 1].length() != 0)
        {
            if (tabla[i][3 - i][0] != tabla[i + 1][3 - i + 1][0])
            {
                mellekatlo[0] = false;
            }
            if (tabla[i][3 - i][1] != tabla[i + 1][3 - i + 1][1])
            {
                mellekatlo[1] = false;
            }
            if (tabla[i][3 - i][2] != tabla[i + 1][3 - i + 1][2])
            {
                mellekatlo[2] = false;
            }
            if (tabla[i][3 - i][3] != tabla[i + 1][3 - i + 1][3])
            {
                mellekatlo[3] = false;
            }
        }
    }
    for (int x = 0; x < 4; x++)
    {
        if (mellekatlo[x] == true && figy4 == true)
            return false;
    }
    return true;
}
int* gepmax(int gepbabu, string* babuk, string tabla[4][4], int masodperc)
{
    float mina = 100;
    int minn, minm;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (tabla[i][j].length() == 0)
            {
                int oszlopos[] = { 0,0,0,0 };
                int soros[] = { 0,0,0,0 };
                int foatlos[] = { 0,0,0,0 };
                int mellekatlos[] = { 0,0,0,0 };
                for (int o = 0; o < 4; ++o)
                {
                    if (o != i)
                    {
                        if (tabla[o][j].length() == 0)
                        {
                            for (int x = 0; x < 4; x++)
                            {
                                oszlopos[x]++;
                            }
                        }
                        else
                        {
                            for (int x = 0; x < 4; x++)
                            {
                                if (tabla[o][j][x] != babuk[gepbabu][x])
                                {
                                    oszlopos[x] = 10;
                                }
                            }
                        }

                    }
                }
                for (int s = 0; s < 4; ++s)
                {
                    if (s != j)
                    {
                        if (tabla[i][s].length() == 0)
                        {
                            for (int x = 0; x < 4; x++)
                            {
                                soros[x]++;
                            }
                        }
                        else
                        {
                            for (int x = 0; x < 4; x++)
                            {
                                if (tabla[i][s][x] != babuk[gepbabu][x])
                                {
                                    soros[x] = 10;
                                }
                            }
                        }
                    }
                }
                if (i == j)
                {
                    for (int m = 0; m < 4; ++m)
                    {
                        if (m != j)
                        {
                            if (tabla[m][m].length() == 0)
                            {
                                for (int x = 0; x < 4; x++)
                                {
                                    foatlos[x]++;
                                }
                            }
                            else
                            {
                                for (int x = 0; x < 4; x++)
                                {
                                    if (tabla[m][m][x] != babuk[gepbabu][x])
                                    {
                                        foatlos[x] = 10;
                                    }
                                }
                            }
                        }
                    }
                }
                if (i == 3 - j)
                {
                    for (int f = 0; f < 4; ++f)
                    {
                        if (f != i)
                        {
                            if (tabla[f][3 - f].length() == 0)
                            {
                                for (int x = 0; x < 4; x++)
                                {
                                    mellekatlos[x]++;
                                }
                            }
                            else
                            {
                                for (int x = 0; x < 4; x++)
                                {
                                    if (tabla[f][3 - f][x] != babuk[gepbabu][x])
                                    {
                                        mellekatlos[x] = 10;
                                    }
                                }
                            }
                        }
                    }
                }
                int ossz1 = 0, db1 = 0;
                int ossz2 = 0, db2 = 0;
                int ossz3 = 0, db3 = 0;
                int ossz4 = 0, db4 = 0;
                for (int q = 0; q < 4; q++)
                {
                    if (oszlopos[q] < 10)
                    {
                        ossz1 += oszlopos[q];
                        db1++;
                        if (oszlopos[q] == 0)
                        {
                            int poz[] = { i,j };
                            return poz;
                        }
                    }
                    if (soros[q] < 10)
                    {
                        ossz2 += soros[q];
                        db2++;
                        if (soros[q] == 0)
                        {
                            int poz[] = { i,j };
                            return poz;
                        }
                    }
                }
                if (i == j)
                {
                    for (int m = 0; m < 4; m++)
                    {
                        if (foatlos[m] < 10)
                        {
                            ossz3 += foatlos[m];
                            db3++;
                            if (foatlos[m] == 0)
                            {
                                int poz[] = { i,j };
                                return poz;
                            }
                        }
                    }
                }
                if (i == 3 - j)
                {
                    for (int m = 0; m < 4; m++)
                    {
                        if (mellekatlos[m] < 10)
                        {
                            ossz4 += mellekatlos[m];
                            db4++;
                            if (mellekatlos[m] == 0)
                            {
                                int poz[] = { i,j };
                                return poz;
                            }
                        }
                    }
                }
                db1 = db1 + db2 + db3 + db4;
                ossz1 = ossz1 + ossz2 + ossz3 + ossz4;
                float a = (float)ossz1;
                float b = (float)db1;
                float arany = (float)a / b;
                if (arany < mina)
                {
                    mina = arany;
                    minn = i;
                    minm = j;
                }

            }
        }
    }
    int poz[] = { minn,minm };

    return poz;
}
int jatekmin(string* babuk, string tabla[4][4])
{
    int finalbabu;
    int maxeset = 0;
    for (int p = 1; p <= 16; ++p)
    {

        bool vegso2 = true;
        if (babuk[p][4] == 'i')
        {
            int gepbabu = p;
            int legjobbeset = 50;
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    if (tabla[i][j].length() == 0)
                    {
                        int oszlopos[] = { 0,0,0,0 };
                        int soros[] = { 0,0,0,0 };
                        int foatlos[] = { 0,0,0,0 };
                        int mellekatlos[] = { 0,0,0,0 };
                        for (int o = 0; o < 4; ++o)
                        {
                            if (o != i)
                            {
                                if (tabla[o][j].length() == 0)
                                {
                                    for (int x = 0; x < 4; x++)
                                    {
                                        oszlopos[x]++;
                                    }
                                }
                                else
                                {
                                    for (int x = 0; x < 4; x++)
                                    {
                                        if (tabla[o][j][x] != babuk[gepbabu][x])
                                        {
                                            oszlopos[x] = 10;
                                        }
                                    }
                                }

                            }
                        }
                        for (int s = 0; s < 4; ++s)
                        {
                            if (s != j)
                            {
                                if (tabla[i][s].length() == 0)
                                {
                                    for (int x = 0; x < 4; x++)
                                    {
                                        soros[x]++;
                                    }
                                }
                                else
                                {
                                    for (int x = 0; x < 4; x++)
                                    {
                                        if (tabla[i][s][x] != babuk[gepbabu][x])
                                        {
                                            soros[x] = 10;
                                        }
                                    }
                                }
                            }
                        }
                        if (i == j)
                        {
                            for (int m = 0; m < 4; ++m)
                            {
                                if (m != j)
                                {
                                    if (tabla[m][m].length() == 0)
                                    {
                                        for (int x = 0; x < 4; x++)
                                        {
                                            foatlos[x]++;
                                        }
                                    }
                                    else
                                    {
                                        for (int x = 0; x < 4; x++)
                                        {
                                            if (tabla[m][m][x] != babuk[gepbabu][x])
                                            {
                                                foatlos[x] = 10;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (i == 3 - j)
                        {
                            for (int f = 0; f < 4; ++f)
                            {
                                if (f != i)
                                {
                                    if (tabla[f][3 - f].length() == 0)
                                    {
                                        for (int x = 0; x < 4; x++)
                                        {
                                            mellekatlos[x]++;
                                        }
                                    }
                                    else
                                    {
                                        for (int x = 0; x < 4; x++)
                                        {
                                            if (tabla[f][3 - f][x] != babuk[gepbabu][x])
                                            {
                                                mellekatlos[x] = 10;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        for (int q = 0; q < 4; q++)
                        {
                            if (oszlopos[q] < 10 && oszlopos[q] < legjobbeset)
                            {
                                legjobbeset = oszlopos[q];
                            }

                            if (soros[q] < 10 && soros[q] < legjobbeset)
                            {
                                legjobbeset = soros[q];
                            }
                        }
                        if (i == j)
                        {
                            for (int m = 0; m < 4; m++)
                            {
                                if (foatlos[m] < 10 && foatlos[m] < legjobbeset)
                                {
                                    legjobbeset = foatlos[m];
                                }
                            }
                        }
                        if (i == 3 - j)
                        {
                            for (int m = 0; m < 4; m++)
                            {
                                if (mellekatlos[m] < 10 && mellekatlos[m] < legjobbeset)
                                {
                                    legjobbeset = mellekatlos[m];
                                }
                            }
                        }

                    }
                }


            }
            if (legjobbeset > maxeset)
            {
                maxeset = legjobbeset;
                finalbabu = p;
            }
        }


    }

    return finalbabu;
}
