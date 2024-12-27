#include <stdio.h>
#include <stdlib.h>
#include "dsp.h"
Dsp dsp;
FILE *fp;

void write_test_file(int val){
        fwrite(&val,2,1,fp);
}
#include <string>
using namespace std;
//string new_data0="F223BB95AD65948B3CAD19AB7C488FC7C862F93AD496EDA39C8AAE2C18750401719969A2FD3D2371EA15E590609E9EEDFAF477B7A5A7F53D237161560EACCA055ADB5AD0353900A7F535A3706917088F42623AF31AA091272EA3FCB4A2706997008D400039EB12A033C8202BC1AB32716A97A29B3D1639F31A25ABFAC01505565D96F59A2768A438ACF263E08AE74C5006D75CBB7580396ED45DA692018C";
string new_data3000="F4BD5372E90E5FBE411F59D9A9A21588A5EFF43D5472EA0E3EADC22A7DDD09A737B8842BF43DCC71EA4E38AC422C5AD3E9A0375805EBFBBCC3916A8E9BBC3D5B7BC331B1D52740EFFA323B95F3CD16BBC07A56BD692273399069F919BB91EA4D9DAD452A3CC1B9B51108029BF999BA712BCE297BC165D8CAE9D12F58E55AF1324C9612CFB47BCE01DC0C82E10F3B201FF143CC91F351087FCD12D4845A4231DD849EF143C4713497017CD61BF20233918FCBD0DFF93A3C71BCDA856A6A3EFBAC63B88F570A9FF11A33516CDD056DA144184DC3F22F56F25FFA1A3351F45AB16F4808FC966BC65169C023F21B3331AB9D138FCFA6FBCA5B884F5AA463FA92324D345F828EC80A1801544211096163FA9A3A71B5A02F7E460CFA241CC32F990A5FF223BB5135625D8D46C41A650CADCF2843DFFA1A3B5133E4427CBE2BFD7C64900F88085FF19AC3513464337C403DD98E84A0CDA8F962F109BA712C68C2651F0DA4E2B4362B164193F081B991EC66C237B4149C20FD0A09E0190FF0893192ECA72B2CDA88789CDCE1072F8013F8883A96ACE7923D2C9C9ADC2C2D8758F70EF0183B96EC28A52BD07B70300D270548D105F112CB95F4F450225EAFBE98E213E9C9C85BF19ACA716B1E286F20099A5A4B24295C4C12F133CB75F31C354C962574A47B92C7077412FA3D4B76";
string new_data2600="F223BB953575001069D8DE46E51350545A26F42CA24CE24A01AFD3865EADF9B05528E0A2FC341250A20D178D4D5B3BC56974D3386023F3340A502A4F028CB92DFBD4E1B17189651FFC3C0A50EA8EB38F3D11FDD809B30F184A63FC3C0A50E2CE957E3F02FDD4C9A1B1A84723FC340A7062CF026F4545DB0022D0515940E7FB340A706A11118D4800164B1AC093D9E7A2FB340A70A253007E4D0A3B9BAA840F9950A7FB341250E195888DD42A18F5F280CFE96163FBB41250A258808C490F1F2D6BBC0D5911A3F2341250AA5A157B4A0F1B7363820F99001BFA2B1A50A2DC527C4602F8A09B8BCDA86397F2A3A22CAA9DE06CC48DDBB27BD3AD960117F999A271AB9C326B4404B9AE33E748EEF215F1912A722C9B435A560B778AFBA889672C13F1992A72F45B";
int main(){
        fp=fopen("./3000dump.output","wb");
        dsp.reset();
        for(int i=0;i<new_data3000.size();i+=2){
                int idx=i/2;
                int inner_idx=idx%18;
                int x;
                if(inner_idx==0) printf("----\n");
                sscanf(&new_data3000[0]+i, "%02x",&x);
                if(inner_idx==0){
                        x&=0x1f;
                }
                if(inner_idx==17){
                        //x&=0x8f;
                }
                printf("%d %02x\n",inner_idx,x);
                dsp.clpBuf[inner_idx]=x;
                if(inner_idx==17)
                dsp.raw_input();
        }
        fclose(fp);

        fp=fopen("./2600dump.output","wb");
        dsp.reset();
        for(int i=0;i<new_data2600.size();i+=2){
                int idx=i/2;
                int inner_idx=idx%18;
                int x;
                if(inner_idx==0) printf("----\n");
                sscanf(&new_data2600[0]+i, "%02x",&x);
                if(inner_idx==0){
                        x&=0x1f;
                }
                if(inner_idx==17){
                        //x&=0x8f;
                }
                printf("%d %02x\n",inner_idx,x);
                dsp.clpBuf[inner_idx]=x;
                if(inner_idx==17)
                dsp.raw_input();
        }
        fclose(fp);
        /*

        for(int i=0;i<sizeof(test_data)/2;i++){
                dsp.write(test_data[i*2+1], test_data[i*2]);
        }

        fp=fopen("./2.output","wb");
        for(int i=0;i<sizeof(test_data2)/2;i++){
                dsp.write(test_data2[i*2+1], test_data2[i*2]);
        }
        fclose(fp);
        fp=fopen("./3_2.output","wb");
        for(int i=0;i<sizeof(test_data3)/2;i++){
                dsp.write(test_data3[i*2+1], test_data3[i*2]);
        }
        fclose(fp);*/
        return 0;
}
