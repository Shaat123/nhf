#include "recepttar.h"
#include "memtrace.h"

ReceptTar::ReceptTar(){
    FILE.open(FILENAME, std::fstream::in);


    if(!FILE.is_open())
        throw  std::runtime_error("Fajl nem nyilt meg");
    else{
        //receptek szamolasa

        char s[400]={0};
        n=0;
        int part=0;
        receptek=new Recept[MAXRECEPT];
        while(FILE.getline(s, 400)){
            if(part==0){
				String line(s);
				if (line.find("<cim end>")){
                    part=1;
                    continue;
                }
				line += '\n';
                receptek[n].add_cim(line);
            }
            else if(part==1){
				String line(s);
				if (line.find("<hv end>")){
                    part=2;
                    continue;
                }
				line += '\n';
				receptek[n].add_hv(line);

            }
            else if(part==2){
				String line(s);
				if (line.find("<szoveg end>")){
                    if(!FILE.eof())
                        n++;
                    part=0;
                    continue;
                }
				line += '\n';
				receptek[n].add_szoveg(line);
            }
        }

    }
    FILE.close();
}

ReceptTar::~ReceptTar(){
    if (receptek!=NULL)
        delete[] receptek;
}

void ReceptTar::kiir(){
    rendez();
    for(int i=0; i<=n; i++){
        receptek[i].kiir();
        std::cout<<std::endl;
    }

}

void ReceptTar::ment(){
    rendez();
    FILE.open(FILENAME, std::fstream::out);
    for(int i=0; i<=n; i++){
        receptek[i].ment(FILE);
        FILE<<std::endl;
    }
    FILE.close();
}

void ReceptTar::rendez() {
    Recept temp;
    for (int i = 1; i<n; i++) {
      for (int j = 0; j <n - 1; j++) {
         if (receptek[j].getcim()>receptek[j+1].getcim()) {
            temp = receptek[j];
            receptek[j] = receptek[j + 1];
            receptek[j + 1] = temp;

         }
      }
    }
}
void ReceptTar::urit(){
    delete[] receptek;
    n=0;
}
void ReceptTar::DB_replace(){
    urit();
    FILE.open(FILENAME, std::fstream::in);

    if(!FILE.is_open())
        throw  std::runtime_error("Fajl nem nyilt meg");
    else{
        //receptek szamolasa

		char s[400] = { 0 };
		n = 0;
		int part = 0;
		receptek = new Recept[MAXRECEPT];
		while (FILE.getline(s, 400)){
			if (part == 0){
				String line(s);
				if (line.find("<cim end>")){
					part = 1;
					continue;
				}
				line += '\n';
				receptek[n].add_cim(line);
			}
			else if (part == 1){
				String line(s);
				if (line.find("<hv end>")){
					part = 2;
					continue;
				}
				line += '\n';
				receptek[n].add_hv(line);

			}
			else if (part == 2){
				String line(s);
				if (line.find("<szoveg end>")){
					if (!FILE.eof())
						n++;
					part = 0;
					continue;
				}
				line += '\n';
				receptek[n].add_szoveg(line);
			}
		}

    }
    FILE.close();

}
void ReceptTar::DB_csere(const char* filepath){
    FILENAME=filepath;
}

void ReceptTar::set_maxrecept(int i){
    MAXRECEPT=i;
}

const char* ReceptTar::FILENAME="receptek.dat";
int ReceptTar::MAXRECEPT=100;
