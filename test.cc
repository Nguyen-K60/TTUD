#include <bits/stdc++.h> 

using namespace std;
int main()
{
	FILE *fp;
        std::ostringstream ss;
        fp = fopen("test.txt", "w+");
       fputs((std::to_string(12.34)+"\n").c_str(), fp);
       fputs((std::to_string(13.45)+"\n").c_str(), fp);
        fclose(fp);
        char buff[64];
        std::string s;
        float r;
        fp = fopen("test.txt", "r");
        while(fgets(buff, 64, (FILE*)fp))
        {
        	r = atof(buff);
        	printf("%f\n", r );
        }
        fclose(fp);
	return 0;
}