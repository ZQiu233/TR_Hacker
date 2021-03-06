#include "Func.h"



void* playerarrbase,*dropeditembase,*npcarrbase;
void* tile,*netMode;
void* Terraria_Main_DrawInterface_Resources_Life,*Terraria_Item_SetDefaults,*Terraria_Item_Prefix,*Terraria_NPC_AddBuff,*Terraria_NPC_NewNPC,*Terraria_Player_AddBuff,*Terraria_NetMessage_SendData,*Terraria_Main_Update,*Terraria_WorldGen_SquareTileFrame,*Terraria_NetMessage_sendWater,*Terraria_Map_WorldMap_UpdateLighting;
void* Terraria_Main_AnglerQuestSwap;

HANDLE hProcess;
int itemArrOff=0xbc;


tag_OFFSET_ITEM OFFSET_ITEM;

void SaveOffset()
{
    FILE *fp=fopen("offsets.txt","wb+");
    int *ptr=(int*)&OFFSET_ITEM;
    for(int i=0; i<sizeof(OFFSET_ITEM)/4; i++)
    {
        int data=ptr[i];
        char str[20];
        sprintf(str,"%x",data);
        fputs(str,fp);
        fputc('\n',fp);
    }
    fclose(fp);
}

void InitOffset()
{
    void* Terraria_Item_ResetStats;
    SearchFunctionByName(L"Terraria.Item::ResetStats",&Terraria_Item_ResetStats,1);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xb,&OFFSET_ITEM.sentry,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x12,&OFFSET_ITEM.DD2Summon,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x19,&OFFSET_ITEM.shopSpecialCurrency,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x23,&OFFSET_ITEM.shopCustomPrice,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x30,&OFFSET_ITEM.expert,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x37,&OFFSET_ITEM.expertOnly,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x3e,&OFFSET_ITEM.instanced,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x45,&OFFSET_ITEM.thrown,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x4c,&OFFSET_ITEM.questItem,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x55,&OFFSET_ITEM.fishingPole,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x58,&OFFSET_ITEM.bait,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x5c,&OFFSET_ITEM.hairDye,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x65,&OFFSET_ITEM.makeNPC,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x6b,&OFFSET_ITEM.dye,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x71,&OFFSET_ITEM.paint,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x77,&OFFSET_ITEM.tileWand,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x7e,&OFFSET_ITEM.notAmmo,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x84,&OFFSET_ITEM.netID,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x8a,&OFFSET_ITEM.prefix,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x90,&OFFSET_ITEM.crit,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x96,&OFFSET_ITEM.mech,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x9c,&OFFSET_ITEM.flame,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xa2,&OFFSET_ITEM.reuseDelay,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xa8,&OFFSET_ITEM.melee,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xae,&OFFSET_ITEM.magic,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xb4,&OFFSET_ITEM.ranged,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xba,&OFFSET_ITEM.summon,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xc0,&OFFSET_ITEM.placeStyle,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xc6,&OFFSET_ITEM.buffTime,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xcc,&OFFSET_ITEM.buffType,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xd2,&OFFSET_ITEM.mountType,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xdc,&OFFSET_ITEM.cartTrack,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xe2,&OFFSET_ITEM.material,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xe8,&OFFSET_ITEM.noWet,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xee,&OFFSET_ITEM.vanity,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xf4,&OFFSET_ITEM.mana,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xfa,&OFFSET_ITEM.wet,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0xfd,&OFFSET_ITEM.wetCount,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x100,&OFFSET_ITEM.lavaWet,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x103,&OFFSET_ITEM.channel,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x109,&OFFSET_ITEM.manaIncrease,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x10f,&OFFSET_ITEM.release,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x115,&OFFSET_ITEM.noMelee,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x11b,&OFFSET_ITEM.noUseGraphic,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x121,&OFFSET_ITEM.lifeRegen,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x129,&OFFSET_ITEM.shootSpeed,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x12f,&OFFSET_ITEM.active,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x133,&OFFSET_ITEM.alpha,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x13f,&OFFSET_ITEM.ammo,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x145,&OFFSET_ITEM.useAmmo,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x14b,&OFFSET_ITEM.autoReuse,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x152,&OFFSET_ITEM.accessory,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x15b,&OFFSET_ITEM.axe,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x161,&OFFSET_ITEM.healMana,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x167,&OFFSET_ITEM.bodySlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x171,&OFFSET_ITEM.legSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x17b,&OFFSET_ITEM.headSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x185,&OFFSET_ITEM.potion,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x18b,&OFFSET_ITEM.color,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x192,&OFFSET_ITEM.glowMask,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x19a,&OFFSET_ITEM.consumable,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1a0,&OFFSET_ITEM.createTile,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1aa,&OFFSET_ITEM.createWall,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1b4,&OFFSET_ITEM.damage,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1be,&OFFSET_ITEM.defense,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1c4,&OFFSET_ITEM.hammer,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1ca,&OFFSET_ITEM.healLife,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1d0,&OFFSET_ITEM.holdStyle,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1d5,&OFFSET_ITEM.knockBack,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1db,&OFFSET_ITEM.maxStack,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1e5,&OFFSET_ITEM.pick,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1eb,&OFFSET_ITEM.rare,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1f3,&OFFSET_ITEM.scale,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1f9,&OFFSET_ITEM.shoot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x1ff,&OFFSET_ITEM.stack,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x209,&OFFSET_ITEM.ToolTip,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x20c,&OFFSET_ITEM.tileBoost,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x212,&OFFSET_ITEM.useStyle,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x215,&OFFSET_ITEM.UseSound,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x218,&OFFSET_ITEM.useTime,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x21f,&OFFSET_ITEM.useAnimation,1,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x226,&OFFSET_ITEM.value,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x22c,&OFFSET_ITEM.useTurn,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x232,&OFFSET_ITEM.buy,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x238,&OFFSET_ITEM.handOnSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x23f,&OFFSET_ITEM.handOffSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x246,&OFFSET_ITEM.backSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x24d,&OFFSET_ITEM.frontSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x254,&OFFSET_ITEM.shoeSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x25b,&OFFSET_ITEM.waistSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x262,&OFFSET_ITEM.wingSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x269,&OFFSET_ITEM.shieldSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x270,&OFFSET_ITEM.neckSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x277,&OFFSET_ITEM.faceSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x27e,&OFFSET_ITEM.balloonSlot,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x285,&OFFSET_ITEM.uniqueStack,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x28b,&OFFSET_ITEM.favorited,4,NULL);
    ReadProcessMemory(hProcess,Terraria_Item_ResetStats+0x291,&OFFSET_ITEM.type,1,NULL);
    //SaveOffset();
}


WCHAR* getPathShortName(WCHAR *full)
{
    int j=0;
    for(int i=lstrlenW(full); i>0; i--)
    {
        if(full[i]==L'\\')
        {
            j=i;
            break;
        }
    }
    if(j!=0)
    {
        return &full[j+1];
    }
    return NULL;
}

void* getModuleBaseAddress(DWORD PID,WCHAR *name)
{
    HANDLE hSnapShot;
    hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, PID);
    MODULEENTRY32W ModuleEntry32;
    ModuleEntry32.dwSize = sizeof(ModuleEntry32);
    if (Module32FirstW(hSnapShot, &ModuleEntry32))
    {
        do
        {
            WCHAR szExt[5];
            lstrcpyW(szExt, ModuleEntry32.szExePath + lstrlenW(ModuleEntry32.szExePath) - 4);
            if(lstrcmpiW(getPathShortName(ModuleEntry32.szExePath),name)==0)
                return ModuleEntry32.modBaseAddr;
        }
        while (Module32NextW(hSnapShot, &ModuleEntry32));
    }
    CloseHandle(hSnapShot);
    return NULL;
}

int GetNetMode()
{
    int m;
    ReadProcessMemory(hProcess,netMode,&m,4,NULL);
    return m;
}

void DropLiquid(int X,int Y,byte header)
{
    byte b[500],raw_code[7];
    ReadProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
    int blen=getHexCode("83 3D 00000000 01\
                        0F 84 47000000\
                        FF 05 00000000\
                        51\
                        52\
                        50\
                        8B 0D 00000000\
                        B8 00000000\
                        BA 00000000\
                        0FAF 41 0C\
                        01 D0\
                        8B 44 81 18\
                        8B C8\
                        C7 41 0D 00000000\
                        C7 41 0E 00000000\
                        B9 00000000\
                        BA 00000000\
                        6A 01\
                        E8 00000000\
                        58\
                        5A\
                        59\
                        00 00 00000000 00\
                        E9 00 00 00 00",
                        b);
    void* hookAddr=VirtualAllocEx(hProcess, NULL, blen, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    /*char str[20];
    sprintf(str,"%x",hookAddr);
    MessageBox(0,str,str,MB_OK);*/
    void* flagAddr=VirtualAllocEx(hProcess, NULL, 4, MEM_COMMIT, PAGE_READWRITE);
    int *d_flag1=(int*)&b[2];
    int *d_flag2=(int*)&b[15];
    int *d_tile=(int*)&b[24];
    int *d_X1=(int*)&b[29];
    int *d_Y1=(int*)&b[34];
    int *d_liquid=(int*)&b[53];
    int *d_header=(int*)&b[60];
    int *d_X2=(int*)&b[65];
    int *d_Y2=(int*)&b[70];
    int *d_callSTF=(int*)&b[77];
    int *d_code=(int*)&b[84];
    int *d_jmpRet=(int*)&b[blen-4];
    *d_flag1=(int)flagAddr;
    *d_flag2=(int)flagAddr;
    *d_tile=(int)tile;
    *d_X1=X;
    *d_Y1=Y;
    *d_liquid=255;
    *d_header=header;
    *d_X2=X;
    *d_Y2=Y;
    *d_callSTF=Terraria_WorldGen_SquareTileFrame-(hookAddr+77)-4;
    memcpy(d_code,raw_code,7);
    *d_flag2=(int)flagAddr;
    *d_jmpRet=(Terraria_Main_Update+0x2B)-(hookAddr+blen-4)+3;
    byte jmpCode[5];
    jmpCode[0]=0xe9;
    *((int*)&jmpCode[1])=hookAddr-(Terraria_Main_Update+0x2B)-5;
    WriteProcessMemory(hProcess,hookAddr,b,blen,NULL);
    WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,jmpCode,5,NULL);
    while(1)
    {
        int flag=0;
        ReadProcessMemory(hProcess,flagAddr,&flag,4,NULL);
        if(flag==1)
            break;
    }
    WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
    VirtualFreeEx(hProcess,(void*)hookAddr,0,MEM_RELEASE);
    VirtualFreeEx(hProcess,(void*)flagAddr,0,MEM_RELEASE);
}

void SendNetWater(int X,int Y)
{
    byte b[500],raw_code[10];
    ReadProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
    int blen=getHexCode("83 3D 00000000 01\
                        0F 84 19000000\
                        FF 05 00000000\
                        51\
                        52\
                        B9 00000000\
                        BA 00000000\
                        E8 00000000\
                        5A\
                        59\
                        00 00 00000000 00\
                        E9 00 00 00 00",
                        b);
    void* hookAddr=VirtualAllocEx(hProcess, NULL, blen, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    /*char str[20];
    sprintf(str,"%x",hookAddr);
    MessageBox(0,str,str,MB_OK);*/
    void* flagAddr=VirtualAllocEx(hProcess, NULL, 4, MEM_COMMIT, PAGE_READWRITE);
    int *d_flag1=(int*)&b[2];
    int *d_flag2=(int*)&b[15];
    int *d_X=(int*)&b[22];
    int *d_Y=(int*)&b[27];
    int *d_callSW=(int*)&b[32];
    int *d_code=(int*)&b[38];
    int *d_jmpRet=(int*)&b[blen-4];
    *d_flag1=(int)flagAddr;
    *d_flag2=(int)flagAddr;
    *d_X=X;
    *d_Y=Y;
    *d_callSW=Terraria_NetMessage_sendWater-(hookAddr+32)-4;
    memcpy(d_code,raw_code,7);
    *d_jmpRet=(Terraria_Main_Update+0x2B)-(hookAddr+blen-4)+3;
    byte jmpCode[5];
    jmpCode[0]=0xe9;
    *((int*)&jmpCode[1])=hookAddr-(Terraria_Main_Update+0x2B)-5;
    WriteProcessMemory(hProcess,hookAddr,b,blen,NULL);
    WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,jmpCode,5,NULL);
    while(1)
    {
        int flag=0;
        ReadProcessMemory(hProcess,flagAddr,&flag,4,NULL);
        if(flag==1)
            break;
    }
    WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
    VirtualFreeEx(hProcess,(void*)hookAddr,0,MEM_RELEASE);
    VirtualFreeEx(hProcess,(void*)flagAddr,0,MEM_RELEASE);
}


void SendNetMessage(int msgType,int remoteClient,int ignoreClient,int number,float number2,float number3,float number4,int number5,int number6,int number7)
{
    int times=1;
    byte b[500],raw_code[10];
    ReadProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
    int blen=getHexCode("813D  00000000  00000000\
                        0F84 46000000\
                        51\
                        52\
                        B9 00000000\
                        BA 00000000\
                        \
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        \
                        E8 00000000\
                        5A\
                        59\
                        FF 05 00000000\
                        0000 00000000 00\
                        E9 00000000",
                        b);
    void* hookAddr=VirtualAllocEx(hProcess, NULL, blen, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    /*char str[20];
    sprintf(str,"%x",hookAddr);
    MessageBox(0,str,str,MB_OK);*/
    void* flagAddr=VirtualAllocEx(hProcess, NULL, 4, MEM_COMMIT, PAGE_READWRITE);
    int *d_flag1=(int*)&b[2];
    int *d_times=(int*)&b[6];
    int *d_msgType=(int*)&b[19];
    int *d_remoteClient=(int*)&b[24];
    int *d_ignoreClient=(int*)&b[29];
    int *d_number=(int*)&b[39];
    int *d_number2=(int*)&b[44];
    int *d_number3=(int*)&b[49];
    int *d_number4=(int*)&b[54];
    int *d_number5=(int*)&b[59];
    int *d_number6=(int*)&b[64];
    int *d_number7=(int*)&b[69];
    int *d_jmpSend=(int*)&b[74];
    int *d_flag2=(int*)&b[82];
    int *d_code=(int*)&b[86];
    int *d_jmpRet=(int*)&b[blen-4];
    *d_flag1=(int)flagAddr;
    *d_times=times;
    *d_msgType=msgType;
    *d_remoteClient=remoteClient;
    *d_ignoreClient=ignoreClient;
    *d_number=number;
    *d_number2=number2;
    *d_number3=number3;
    *d_number4=number4;
    *d_number5=number5;
    *d_number6=number6;
    *d_number7=number7;
    *d_jmpSend=Terraria_NetMessage_SendData-(hookAddr+74)-4;
    *d_flag2=(int)flagAddr;
    memcpy(d_code,raw_code,7);
    *d_jmpRet=(Terraria_Main_Update+0x2B)-(hookAddr+blen-4)+3;
    byte jmpCode[5];
    jmpCode[0]=0xe9;
    *((int*)&jmpCode[1])=hookAddr-(Terraria_Main_Update+0x2B)-5;
    WriteProcessMemory(hProcess,hookAddr,b,blen,NULL);
    WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,jmpCode,5,NULL);
    while(1)
    {
        int flag=0;
        ReadProcessMemory(hProcess,flagAddr,&flag,4,NULL);
        if(flag==times)
            break;
    }
    WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
    VirtualFreeEx(hProcess,(void*)hookAddr,0,MEM_RELEASE);
    VirtualFreeEx(hProcess,(void*)flagAddr,0,MEM_RELEASE);
}


void NewNPC(float X,float Y,int Type,int number)
{
    byte b[500],raw_code[7];
    ReadProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
    int blen=getHexCode(
                 "813D  00000000  00000000\
                        0F84 3B000000\
                        51\
                        52\
                        B9 00000000\
                        BA 00000000\
                        68 00000000\
                        \
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        68 00000000\
                        E8 00000000\
                        5A\
                        59\
                        FF 05 00000000\
                        0000 00000000 00\
                        E9 00000000"
                 ,b);
    void* hookAddr=VirtualAllocEx(hProcess, NULL, blen, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    void* flagAddr=VirtualAllocEx(hProcess, NULL, 4, MEM_COMMIT, PAGE_READWRITE);
    /*char str[20];
    sprintf(str,"%x",hookAddr);
    MessageBox(0,str,str,MB_OK);*/
    int *d_flag1=(int*)&b[2];
    int *d_number=(int*)&b[6];
    int *d_X=(int*)&b[19];
    int *d_Y=(int*)&b[24];
    int *d_Type=(int*)&b[29];
    int *d_Start=(int*)&b[34];
    int *d_ai0=(int*)&b[39];
    int *d_ai1=(int*)&b[44];
    int *d_ai2=(int*)&b[49];
    int *d_ai3=(int*)&b[54];
    int *d_Target=(int*)&b[59];
    int *d_jmp_NewNPC=(int*)&b[64];
    int *d_flag2=(int*)&b[72];
    int *d_code=(int*)&b[76];
    int *d_jmpRet=(int*)&b[blen-4];
    *d_flag1=(int)flagAddr;
    *d_number=number;
    *d_X=X;
    *d_Y=Y;
    *d_Type=Type;
    *d_Start=0;
    *d_ai0=0;
    *d_ai1=0;
    *d_ai2=0;
    *d_ai3=0;
    *d_Target=getMyPlayer();
    *d_jmp_NewNPC=Terraria_NPC_NewNPC-(hookAddr+64)-4;
    *d_flag2=(int)flagAddr;
    memcpy(d_code,raw_code,7);
    *d_jmpRet=(Terraria_Main_Update+0x2B)-(hookAddr+blen-4)+3;
    byte jmpCode[5];
    jmpCode[0]=0xe9;
    *((int*)&jmpCode[1])=hookAddr-(Terraria_Main_Update+0x2B)-5;
    WriteProcessMemory(hProcess,hookAddr,b,blen,NULL);
    WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,jmpCode,5,NULL);
    while(1)
    {
        int flag=0;
        ReadProcessMemory(hProcess,flagAddr,&flag,4,NULL);
        if(flag==number)
            break;
    }
    WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
    VirtualFreeEx(hProcess,(void*)hookAddr,0,MEM_RELEASE);
    VirtualFreeEx(hProcess,(void*)flagAddr,0,MEM_RELEASE);
}

wchar_t *ReadUUID()
{
    void *Terraria_Main_ClientInitialize;
    SearchFunctionByName(L"Terraria.Main::ClientInitialize",&Terraria_Main_ClientInitialize,1);
    void *v,*v1;
    ReadProcessMemory(hProcess,Terraria_Main_ClientInitialize+0x5c,&v,4,NULL);
    ReadProcessMemory(hProcess,v,&v1,4,NULL);
    wchar_t *UUID=(wchar_t*)malloc(32+4+1);
    ReadProcessMemory(hProcess,v1+8,UUID,(32+4+1)*sizeof(wchar_t),NULL);
    return UUID;
}



int RandomUUID()
{
    void *Terraria_Main_ClientInitialize;
    SearchFunctionByName(L"Terraria.Main::ClientInitialize",&Terraria_Main_ClientInitialize,1);
    void *v,*v1;
    ReadProcessMemory(hProcess,Terraria_Main_ClientInitialize+0x5c,&v,4,NULL);
    ReadProcessMemory(hProcess,v,&v1,4,NULL);
    wchar_t uuid[32+4];
    {
        srand((unsigned)time(NULL));
        char tmp_uuid[32+4];
        for(int i=0; i<32+4; i++)
        {
            if(i==8||i==13||i==18||i==23)
            {
                tmp_uuid[i]='-';
                continue;
            }
            int d=rand()%16;
            sprintf(&tmp_uuid[i],"%x",d);
        }
        wsprintfW(uuid,L"%hs",tmp_uuid);
    }
    WriteProcessMemory(hProcess,v1+8,uuid,(32+4)*sizeof(wchar_t),NULL);
    return 1;
}

int De_EnableAllRecipes()
{
    void *Terraria_Recipe_FindRecipes;
    SearchFunctionByName(L"Terraria.Recipe::FindRecipes",&Terraria_Recipe_FindRecipes,1);
    {
        void *addr;
        ReadProcessMemory(hProcess,Terraria_Recipe_FindRecipes+0xd,&addr,4,NULL);
        addr+=(int)Terraria_Recipe_FindRecipes+0xd+4;
        char str[20];
        sprintf(str,"%x",(unsigned)addr);
        VirtualFreeEx(hProcess,addr,0,MEM_RELEASE);
    }
    byte b[6];
    int blen=getHexCode("8D BD 38 FF FF FF",b);
    WriteProcessMemory(hProcess,Terraria_Recipe_FindRecipes+0xc,b,blen,NULL);
    return 1;
}

int EnableAllRecipes()
{
    void *Terraria_Recipe_FindRecipes;
    SearchFunctionByName(L"Terraria.Recipe::FindRecipes",&Terraria_Recipe_FindRecipes,1);
    byte b[256];
    byte jmp_code[6];
    int blen=getHexCode("8D 65 F4  5B 5E 5F 5D C3",b);
    void* hookAddr=VirtualAllocEx(hProcess, NULL, blen, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    jmp_code[0]=0xe9;
    jmp_code[5]=0x90;
    int *d_jmp_to=(int*)&jmp_code[1];
    *d_jmp_to=hookAddr-(Terraria_Recipe_FindRecipes+0xC)-5;
    WriteProcessMemory(hProcess,hookAddr,b,blen,NULL);
    WriteProcessMemory(hProcess,Terraria_Recipe_FindRecipes+0xC,jmp_code,6,NULL);
    //Sleep(60);
    void *recipeArrAddr=0,*maxRecipe=0;
    {
        void *v;
        ReadProcessMemory(hProcess,Terraria_Recipe_FindRecipes+0x1c,&v,4,NULL);
        ReadProcessMemory(hProcess,v,&recipeArrAddr,4,NULL);
        v=(void*)aobscan(hProcess,"00 8b 85 e8 fd ff ff 3b 05",0);
        ReadProcessMemory(hProcess,v+0x9,&maxRecipe,4,NULL);
        /*char str[20];
        sprintf(str,"%x",v);
        MessageBox(0,str,str,MB_OK);*/
    }
    int MAX=2000;
    for(int i=0; i<MAX; i++)
    {
        void* addr=recipeArrAddr+0x08+i*0x04;
        WriteProcessMemory(hProcess,addr,&i,4,NULL);
    }
    WriteProcessMemory(hProcess,maxRecipe,&MAX,4,NULL);
    return 1;
}

byte getNPCActive(int nid)
{
    byte v;
    _Read_FromBase(npcarrbase,&v,1,2,0x8+nid*0x4,0x18);
    return v;
}

void NPC_AddBuff(int nid,int buff,int time)
{
    int addr;
    {
        ReadProcessMemory(hProcess,(void*)(npcarrbase+0x08+0x04*nid),&addr,4,NULL);
    }
    byte b[500],raw_code[7];
    ReadProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
    ///mov flag,0
    ///push ecx
    ///push edx
    ///mov ecx,base
    ///mov edx,buffType
    ///push buffTime
    ///push quiet
    ///call Terraria.NPC::AddBuff
    ///pop edx
    ///pop ecx
    ///fild dword ptr [edx+00000340]
    ///mov flag,1
    ///jmp back
    int blen=getHexCode("C7 05 00 00 00 00 00 00 00 00\
                        51\
                        52\
                        B9 00 00 00 00\
                        BA 00 00 00 00\
                        68 00 00 00 00\
                        6A 00\
                        E8 00 00 00 00\
                        5A\
                        59\
                        0000 00000000 00\
                        C7 05 00 00 00 00 01 00 00 00\
                        E9 00 00 00 00",
                        b);
    void* hookAddr=VirtualAllocEx(hProcess, NULL, blen, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    /*char str[20];
    sprintf(str,"%x",hookAddr);
    MessageBox(0,str,str,MB_OK);*/
    void* flagAddr=VirtualAllocEx(hProcess, NULL, 4, MEM_COMMIT, PAGE_READWRITE);
    int *d_flag1=(int*)&b[2];
    int *d_Base=(int*)&b[13];
    int *d_buffType=(int*)&b[18];
    int *d_buffTime=(int*)&b[23];
    int *d_jmpAddBuff=(int*)&b[30];
    int *d_code=(int*)&b[36];
    int *d_flag2=(int*)&b[45];
    int *d_jmpRet=(int*)&b[blen-4];
    *d_flag1=(int)flagAddr;
    *d_Base=addr;
    *d_buffType=buff;
    *d_buffTime=time;
    *d_jmpAddBuff=Terraria_NPC_AddBuff-(hookAddr+30)-4;
    memcpy(d_code,raw_code,7);
    *d_flag2=(int)flagAddr;
    *d_jmpRet=(Terraria_Main_Update+0x2B)-(hookAddr+blen-4)+3;
    byte jmpCode[5];
    jmpCode[0]=0xe9;
    *((int*)&jmpCode[1])=hookAddr-(Terraria_Main_Update+0x2B)-5;
    WriteProcessMemory(hProcess,hookAddr,b,blen,NULL);
    WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,jmpCode,5,NULL);
    while(1)
    {
        int flag=0;
        ReadProcessMemory(hProcess,flagAddr,&flag,4,NULL);
        if(flag==1)
            break;
    }
    WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
    VirtualFreeEx(hProcess,(void*)hookAddr,0,MEM_RELEASE);
    VirtualFreeEx(hProcess,(void*)flagAddr,0,MEM_RELEASE);
}

void Player_AddBuff(int pid,int buff,int time)
{
    int addr;
    {
        ReadProcessMemory(hProcess,(void*)(playerarrbase+0x08+0x04*pid),&addr,4,NULL);
    }
    byte b[500],raw_code[7];
    ReadProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
    ///mov flag,0
    ///push ecx
    ///push edx
    ///mov ecx,base
    ///mov edx,buffType
    ///push buffTime
    ///push quiet
    ///call Terraria.NPC::AddBuff
    ///pop edx
    ///pop ecx
    ///fild dword ptr [edx+00000340]
    ///mov flag,1
    ///jmp back
    int blen=getHexCode("C7 05 00 00 00 00 00 00 00 00\
                        51\
                        52\
                        B9 00 00 00 00\
                        BA 00 00 00 00\
                        68 00 00 00 00\
                        6A 00\
                        E8 00 00 00 00\
                        5A\
                        59\
                        0000 00000000 00\
                        C7 05 00 00 00 00 01 00 00 00\
                        E9 00 00 00 00",
                        b);
    void* hookAddr=VirtualAllocEx(hProcess, NULL, blen, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    /*char str[20];
    sprintf(str,"%x",hookAddr);
    MessageBox(0,str,str,MB_OK);*/
    void* flagAddr=VirtualAllocEx(hProcess, NULL, 4, MEM_COMMIT, PAGE_READWRITE);
    int *d_flag1=(int*)&b[2];
    int *d_Base=(int*)&b[13];
    int *d_buffType=(int*)&b[18];
    int *d_buffTime=(int*)&b[23];
    int *d_jmpAddBuff=(int*)&b[30];
    int *d_code=(int*)&b[36];
    int *d_flag2=(int*)&b[45];
    int *d_jmpRet=(int*)&b[blen-4];
    *d_flag1=(int)flagAddr;
    *d_Base=addr;
    *d_buffType=buff;
    *d_buffTime=time;
    *d_jmpAddBuff=Terraria_Player_AddBuff-(hookAddr+30)-4;
    memcpy(d_code,raw_code,7);
    *d_flag2=(int)flagAddr;
    *d_jmpRet=(Terraria_Main_Update+0x2B)-(hookAddr+blen-4)+3;
    byte jmpCode[5];
    jmpCode[0]=0xe9;
    *((int*)&jmpCode[1])=hookAddr-(Terraria_Main_Update+0x2B)-5;
    WriteProcessMemory(hProcess,hookAddr,b,blen,NULL);
    WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,jmpCode,5,NULL);
    while(1)
    {
        int flag=0;
        ReadProcessMemory(hProcess,flagAddr,&flag,4,NULL);
        if(flag==1)
            break;
    }
    WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
    VirtualFreeEx(hProcess,(void*)hookAddr,0,MEM_RELEASE);
    VirtualFreeEx(hProcess,(void*)flagAddr,0,MEM_RELEASE);
}


int StrengthenVampireKnives()
{
    void*path=(void*)aobscan(hProcess,"81 78 6c 21 06 00 00 0f 85",0);
    void* numberAddr=path+0x13;
    int v=0x100;
    WriteProcessMemory(hProcess,numberAddr,&v,4,NULL);
    return 1;
}

int De_StrengthenVampireKnives()
{
    void*path=(void*)aobscan(hProcess,"81 78 6c 21 06 00 00 0f 85",0);
    void* numberAddr=path+0x13;
    int v=0x4;
    WriteProcessMemory(hProcess,numberAddr,&v,4,NULL);
    return 1;
}

void SetItemDefaults(int slot,int type,int prefix)
{
    int addr;
    {
        int data;
        ReadProcessMemory(hProcess,(void*)(getPlayerBaseAddress(getMyPlayer())+itemArrOff),&data,4,NULL);
        ReadProcessMemory(hProcess,(void*)(data+0x08+0x04*slot),&addr,4,NULL);
    }
    byte b[500],raw_code[7];
    ReadProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
    ///mov flag,0
    ///push ecx
    ///push edx
    ///mov ecx,base
    ///mov edx,Type
    ///push noMatCheck
    ///call Terraria.Item::SetDefaults
    ///mov ecx,base
    ///mov edx,Prefix
    ///call Terraria.Item::Prefix
    ///pop edx
    ///pop ecx
    ///fild dword ptr [edx+00000340]
    ///mov flag,1
    ///jmp back
    int blen=getHexCode("C7 05 00 00 00 00 00 00 00 00\
                        51\
                        52\
                        B9 00 00 00 00\
                        BA 00 00 00 00\
                        6A 00\
                        E8 00 00 00 00\
                        B9 00 00 00 00\
                        BA 00 00 00 00\
                        E8 00 00 00 00\
                        5A\
                        59\
                        00 00 00000000 00\
                        C7 05 00 00 00 00 01 00 00 00\
                        E9 00 00 00 00",
                        b);
    void* hookAddr=VirtualAllocEx(hProcess, NULL, blen, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    /*char str[20];
    sprintf(str,"%x",hookAddr);
    MessageBox(0,str,str,MB_OK);*/
    void* flagAddr=VirtualAllocEx(hProcess, NULL, 4, MEM_COMMIT, PAGE_READWRITE);
    int *d_flag1=(int*)&b[2];
    int *d_itemBase=(int*)&b[13];
    int *d_Type=(int*)&b[18];
    int *d_jmpSetDefaults=(int*)&b[25];
    int *d_itemBase1=(int*)&b[30];
    int *d_Prefix=(int*)&b[35];
    int *d_jmpPrefix=(int*)&b[40];
    int *d_code=(int*)&b[46];
    int *d_flag2=(int*)&b[55];
    int *d_jmpRet=(int*)&b[blen-4];
    *d_flag1=(int)flagAddr;
    *d_itemBase=addr;
    *d_Type=type;
    *d_jmpSetDefaults=Terraria_Item_SetDefaults-(hookAddr+25)-4;
    *d_itemBase1=addr;
    *d_Prefix=prefix;
    *d_jmpPrefix=Terraria_Item_Prefix-(hookAddr+40)-4;
    memcpy(d_code,raw_code,7);
    *d_flag2=(int)flagAddr;
    *d_jmpRet=(Terraria_Main_Update+0x2B)-(hookAddr+blen-4)+3;
    byte jmpCode[5];
    jmpCode[0]=0xe9;
    *((int*)&jmpCode[1])=hookAddr-(Terraria_Main_Update+0x2B)-5;
    WriteProcessMemory(hProcess,hookAddr,b,blen,NULL);
    WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,jmpCode,5,NULL);
    while(1)
    {
        int flag=0;
        ReadProcessMemory(hProcess,flagAddr,&flag,4,NULL);
        if(flag==1)
            break;
    }
    WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
    VirtualFreeEx(hProcess,(void*)hookAddr,0,MEM_RELEASE);
    VirtualFreeEx(hProcess,(void*)flagAddr,0,MEM_RELEASE);
}



void setItemArrayOffset(int off)
{
    itemArrOff=off;
}

/*byte PassWord(char *w)
{
    char cpuid[20];
    getCPUID(cpuid);
    char name[100];
    DWORD len=100;
    GetComputerName(name,&len);
    int k=0;
    for(int i=0; i<strlen(name); i++)
    {
        k+=name[i];
    }
    int m=0;
    sscanf(cpuid,"%x",&m);
    m=m%64;
    char *rst=(char*)malloc(1024);
    strcpy(rst,"");
    for(int i=0; i<10; i++)
    {
        if(i<strlen(name))
        {
            int v=(name[i]*strlen(name)+37)*k*m;
            char c[100]="";
            sprintf(c,"%x",v);
            strcat(rst,c);
        }
        else
        {
            int v=(name[i-strlen(name)]*strlen(name)+37)*(k%20)*m;
            char c[100]="";
            sprintf(c,"%x",v);
            strcat(rst,c);
        }
    }
    if(strcmp(rst,w)==0)
    {
        reg=1;
    }
    else
    {
        reg=0;
    }
    free(rst);
    return reg;
}*/

LPSTR GetProcessIdByName(int pid)
{
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hSnapshot)
    {
        return 0;
    }
    PROCESSENTRY32 pe = { sizeof(pe) };
    BOOL fOk;
    for (fOk = Process32First(hSnapshot, &pe); fOk; fOk = Process32Next(hSnapshot, &pe))
    {
        if(pe.th32ProcessID==pid)
        {
            LPSTR s=(LPSTR)malloc(128);
            ZeroMemory(s,128);
            _tcscpy(s,pe.szExeFile);
            return s;
        }
    }
    return 0;
}

int swprintf(wchar_t*,const wchar_t*,...);

void* getPlayerBase(int pid,HANDLE hP)
{
    {
        char *s=GetProcessIdByName(pid);
        PWCHAR module=(PWCHAR)malloc(256);
        ZeroMemory(module,256);
        swprintf(module,L"%hs",s);
        InitCL(pid,TRUE,module);
    }
    SearchFunctionByName(L"Terraria.Main::DrawInterface_Resources_Life",&Terraria_Main_DrawInterface_Resources_Life,1);
    SearchFunctionByName(L"Terraria.Item::SetDefaults",&Terraria_Item_SetDefaults,1);
    SearchFunctionByName(L"Terraria.NPC::AddBuff",&Terraria_NPC_AddBuff,1);
    SearchFunctionByName(L"Terraria.Player::AddBuff",&Terraria_Player_AddBuff,1);
    SearchFunctionByName(L"Terraria.Item::Prefix",&Terraria_Item_Prefix,1);
    SearchFunctionByName(L"Terraria.NPC::NewNPC",&Terraria_NPC_NewNPC,1);
    SearchFunctionByName(L"Terraria.NetMessage::SendData",&Terraria_NetMessage_SendData,1);
    SearchFunctionByName(L"Terraria.Main::Update",&Terraria_Main_Update,1);
    SearchFunctionByName(L"Terraria.WorldGen::SquareTileFrame",&Terraria_WorldGen_SquareTileFrame,1);
    SearchFunctionByName(L"Terraria.NetMessage::sendWater",&Terraria_NetMessage_sendWater,1);
    SearchFunctionByName(L"Terraria.Main::AnglerQuestSwap",&Terraria_Main_AnglerQuestSwap,1);

    SearchFunctionByName(L"Terraria.Map.WorldMap::UpdateLighting",&Terraria_Map_WorldMap_UpdateLighting,1);



    hProcess=hP;
    InitEax(pid);
    if(getPlayerBaseAddress(getMyPlayer())<=0)
    {
        return (void*)-1;
    }

    ReadProcessMemory(hProcess,Terraria_Main_AnglerQuestSwap+0x8,&netMode,4,NULL);

    void*pkTile;
    SearchFunctionByName(L"Terraria.Player::PickTile",&pkTile,1);
    ReadProcessMemory(hProcess,pkTile+0x36,&tile,4,NULL);

    void* newItemBase;
    SearchFunctionByName(L"Terraria.Item::NewItem",&newItemBase,3);
    void* e;
    ReadProcessMemory(hProcess,newItemBase+0x73,&e,4,NULL);
    ReadProcessMemory(hProcess,e,&dropeditembase,4,NULL);

    void* npcAddHaightBase;
    SearchFunctionByName(L"Terraria.Main::NPCAddHeight",&npcAddHaightBase,1);
    ReadProcessMemory(hProcess,npcAddHaightBase+0x6,&e,4,NULL);
    ReadProcessMemory(hProcess,e,&npcarrbase,4,NULL);
    InitOffset();
    return getPlayerBaseAddress(getMyPlayer());
}


HWND GetXHandle(LPCSTR procName)
{
    DWORD iProcID=0;

    PROCESSENTRY32 pEntry= {sizeof(PROCESSENTRY32)};

    HANDLE hSnapshot=CreateToolhelp32Snapshot(TH32CS_SNAPALL,0);
    if(hSnapshot!=INVALID_HANDLE_VALUE)
    {
        if(Process32First(hSnapshot,&pEntry))
        {
            while (Process32Next(hSnapshot, &pEntry))
            {
                if(lstrcmpi(procName, pEntry.szExeFile) == 0)
                {
                    iProcID=pEntry.th32ProcessID;
                    CloseHandle(hSnapshot);
                    break;
                }
            }
        }
    }

    HWND hwnd=GetTopWindow(NULL);
    while(hwnd)
    {
        DWORD pid=0;
        DWORD dwProcessId=GetWindowThreadProcessId(hwnd,&pid);

        if(dwProcessId!=0)
        {
            if(pid==iProcID)
            {
                return hwnd;
            }
        }

        hwnd=GetNextWindow(hwnd,GW_HWNDNEXT);
    }
    return NULL;
}


void* inline_hook(HANDLE hProcess,void*path,int dstlen,byte *code,int codelen)
{
    //
    byte *ASM_CODE=(byte*)malloc(codelen+5);
    memcpy(ASM_CODE,code,codelen);
    ASM_CODE[codelen]=0xe9;
    DWORD*retjmp=(DWORD *)&ASM_CODE[codelen+1];
    PWSTR pCode=(PWSTR)VirtualAllocEx(hProcess, NULL, sizeof(codelen+5), MEM_COMMIT, PAGE_EXECUTE);
    *retjmp=(DWORD)path+dstlen-((DWORD)pCode+codelen+5);
    WriteProcessMemory(hProcess,(void*)pCode,(void*)&ASM_CODE[0],codelen+5,NULL);
    //
    byte HookCode[5]= {0xE9};
    DWORD*jmp=(DWORD*)&HookCode[1];
    *jmp=(DWORD)pCode-(DWORD)path-5;
    //hi->HOOK_CODE=malloc(dstlen);
    //hi->HOOK_CODE_LENGTH=dstlen;
    //ReadProcessMemory(hProcess,path,hi->HOOK_CODE,dstlen,NULL);
    WriteProcessMemory(hProcess,path,HookCode,5,NULL);
    //
    //hi->HOOK_PATH=path;
    //hi->ASM_PATH=pCode;
    Sleep(200);
    return pCode;
}
void un_inline_hook(HANDLE hProcess,char *aobstr,char *headstr,int off)
{
    int path1=aobscan(hProcess,aobstr,0);
    if(path1<=0)
    {
        return;
    }
    int path=path1+off;
    byte *b=(byte*)malloc(1024);
    int headlen=getHexCode(headstr,b);
    int addr;
    ReadProcessMemory(hProcess,(void*)(path-headlen+1),&addr,4,NULL);
    /*char str[20];
    sprintf(str,"%x",addr);
    MessageBox(0,str,str,MB_OK);*/
    WriteProcessMemory(hProcess,(void*)(path-headlen),&(b[0]),headlen,NULL);
    VirtualFreeEx(hProcess,(void*)((DWORD)addr+path),0,MEM_RELEASE);
}
void _Read_FromBase(void* baseaddr,void*v,int len,int n,...)
{
    if(!baseaddr)
        return;
    va_list args;
    va_start(args,n);
    //int baseaddr=getPlayerBaseAddress(getMyPlayer());
    while(n>1)
    {
        int off=va_arg(args,int);
        ReadProcessMemory(hProcess,(void*)baseaddr+off,&baseaddr,4,0);
        n--;
    }
    int off=va_arg(args,int);
    ReadProcessMemory(hProcess,(void*)baseaddr+off,v,len,0);
    va_end(args);
}

void _Hack(void* baseaddr,void*v,int len,int n,...)
{
    if(!baseaddr)
        return;
    va_list args;
    va_start(args,n);
    //int baseaddr=getPlayerBaseAddress(getMyPlayer());
    while(n>1)
    {
        int off=va_arg(args,int);
        ReadProcessMemory(hProcess,baseaddr+off,&baseaddr,4,0);
        n--;
    }
    void* t=baseaddr+va_arg(args,int);
    WriteProcessMemory(hProcess,t,v,len,0);
    va_end(args);
}
int search_only(char *src)
{
    int addrs=aobscan(hProcess,src,0);
    return addrs;
}
int search_replace(char *src,char *dst)
{
    int addrs;
    int flag=0;
    while((addrs=aobscan(hProcess,src,0))>-1)
    {
        byte b[256];
        int len=getHexCode(dst,b);
        WriteProcessMemory(hProcess,(void*)addrs,b,len,0);
        flag=1;
    }
    return flag;
}
int memmem(char * a, int alen, char * b, int blen)
{
    int i,j;
    for(i=0; i<alen-blen; ++i)
    {
        for(j=0; j<blen; ++j)
            if(a[i+j]!=b[j])
                break;
        if(j>=blen)
            return i;
    }
    return -1;
}

int ctoh(char hex)
{
    if (hex >= '0' && hex <= '9')
        return hex - '0';
    if (hex >= 'A' && hex <= 'F')
        return hex - 'A' + 10;
    if (hex >= 'a' && hex <= 'f')
        return hex - 'a' + 10;
    return 0;
}

int getHexCode(const char *str,byte *res)
{
    char tmp[2]="";
    int j=0;
    int k=0;
    for(unsigned i=0; i<strlen(str); i++)
    {
        char c=str[i];
        if((c>='0'&&c<='9')||(c>='A'&&c<='Z')||(c>='a'&&c<='z'))
        {
            if(j%2==1)
            {
                tmp[1]=str[i];
                int v=0x10*ctoh(tmp[0])+ctoh(tmp[1]);
                res[k]=v;
                k++;
            }
            else if(j%2==0)
            {
                tmp[0]=str[i];
            }
            j++;
        }
    }
    return k;
}


int aobscan(HANDLE hProcess,const char *aob,int beginaddr)
{
    byte b[256];
    int len=getHexCode(aob,b);
    MEMORY_BASIC_INFORMATION mbi;
    while(beginaddr<0x7fffffff)
    {
        unsigned int flag=VirtualQueryEx(hProcess,(void*)beginaddr,&mbi,sizeof(MEMORY_BASIC_INFORMATION));
        if(flag!=sizeof(MEMORY_BASIC_INFORMATION))
            break;
        if((int)mbi.RegionSize<=0)
            break;
        if(mbi.Protect!=PAGE_EXECUTE_READWRITE||mbi.State!=MEM_COMMIT)
        {
            beginaddr+=mbi.RegionSize;
            continue;
        }
        char *mem=(char*)malloc((int)mbi.RegionSize);
        ReadProcessMemory(hProcess,(void*)beginaddr,mem,(int)mbi.RegionSize,0);
        int r=memmem(mem,(int)mbi.RegionSize,(char*)b,len);
        if(r>=0)
        {
            return beginaddr+r;
        }
        beginaddr+=mbi.RegionSize;
    }
    return -1;
}

int InfiniteHealth()
{
    return search_replace("29 82 40 03 00 00","01 82 40 03 00 00");
}

int InfiniteMana()
{
    int a=search_replace("29 BE 44 03 00 00","01 BE 44 03 00 00");
    int b=search_replace("29 82 44 03 00 00","01 82 44 03 00 00");
    return a||b;
    return 0;
}

int InfiniteMinion()
{
    return search_replace("C7 86 14 02 00 00 01 00 00 00","C7 86 14 02 00 00 0 FF FF FF");
}

int InfiniteItems()
{
    return search_replace("FF 88 80 00 00 00 8B 45 08","90 90 90 90 90 90 8B 45 08");
}

int InfiniteFly()
{
    return search_replace("D9 99 20 02 00 00 5D C3 00","90 90 90 90 90 90 5D C3 00");
}

int AwfulFishingSkill()
{
    return search_replace("83 83 00 02 00 00 0F E9 A1 3B 00 00","83 83 00 02 00 00 64 E9 A1 3B 00 00");
}

int GhostMode()
{
    char v=1;
    _Hack(getPlayerBaseAddress(getMyPlayer()),&v,1,1,0x549);
    return 0;
}

int InfiniteOxygen()
{
    return search_replace("FF 88 B4 02 00 00 83 B8 B4 02 00 00 00","90 90 90 90 90 90 83 B8 B4 02 00 00 00");
}

int InfiniteBullet()
{
    return search_replace("FF 8B 80 00 00 00 83 BB 80","90 90 90 90 90 90");
}

int NoRespawnTime()
{
    return search_replace("C7 86 E8 02 00 00 58 02 00 00","C7 86 E8 02 00 00 00 00 00 00");
}

int AttackThroughWalls()
{
    return search_replace("0F 85 D4 03 00 00 8D 55","E9 D5 03 00 00 90 8D 55");
}

int ProjectileIgnoreTiles()
{
    void* Terraria_Projectile_HandleMovement;
    SearchFunctionByName(L"Terraria.Projectile::HandleMovement",&Terraria_Projectile_HandleMovement,1);
    int aAddr=(int)ceil((int)Terraria_Projectile_HandleMovement/0x10000)*0x10000;
    byte v=0x8d;
    WriteProcessMemory(hProcess,(void*)aobscan(hProcess,"8d 7d d8",aAddr)-0x5,&v,1,NULL);
    return 1;
}

int JumpAsFeather()
{
    int path=aobscan(hProcess,"89 96 14 04 00 00",0);
    if(path<=0)
    {
        return 0;
    }
    path-=6;
    byte ASM_CODE[]= {0xC7,0x86,0x10,0x04,0x00,0x00,0x00,0x00,0x20,0x41};
    inline_hook(hProcess,(void*)path,6,ASM_CODE,sizeof(ASM_CODE));
    return 1;
}


int FastSpeed()
{
    int path=aobscan(hProcess,"D9 9E BC 03 00 00 88 96 4B 05 00 00 88 96 4D 05 00 00",0);
    if(path<=0)
    {
        return 0;
    }
    byte ASM_CODE[]= {0xC7,0x86,itemArrOff,0x03,0x00,0x00,0x00,0x20,0x4B,0x46, 0xC7,0x86,0xE4,0x03,0x00,0x00,0x00,0x20,0x4B,0x46};//700????0xC7,0x86,itemArrOff,0x03,0x00,0x00,0x00,0x40,0x9C,0x45,0xC7,0x86,0xE4,0x03,0x00,0x00,0x00,0x40,0x9C,0x45
    inline_hook(hProcess,(void*)path,6,ASM_CODE,sizeof(ASM_CODE));
    return 1;
}


int KillAllNPC()
{
    int path=aobscan(hProcess,"8B 80 F4 00 00 00 8B 95 C4 B0 FF FF 3B 82 F8 00 00 00 0F 8C",0);
    if(path<=0)
    {
        return 0;
    }
    byte ASM_CODE[]= {0xC7,0x80,0xF4,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    inline_hook(hProcess,(void*)path,6,ASM_CODE,sizeof(ASM_CODE));
    return 1;
}

int GrabItemFarAway()
{
    int path=aobscan(hProcess,"80 BB 2E 06 00 00 00 74",0);
    int a=path+20;
    int b=path+15;
    int c=path+7;
    int y=path+23;
    int rangeaddr;
    ReadProcessMemory(hProcess,(void*)y,&rangeaddr,4,NULL);
    byte co[]= {0x90,0x90};
    WriteProcessMemory(hProcess,(void*)a,(void*)&co[0],2,NULL);
    WriteProcessMemory(hProcess,(void*)b,(void*)&co[0],2,NULL);
    WriteProcessMemory(hProcess,(void*)c,(void*)&co[0],2,NULL);
    int range=1000;
    WriteProcessMemory(hProcess,(void*)rangeaddr,(void*)&range,4,NULL);
    return 1;
}

int ToggleTime()
{
    int path1=aobscan(hProcess,"8B 48 28 39 09 FF 15",0);
    if(path1<=0)
    {
        return 0;
    }
    int path=path1+0x84;
    int timeaddr;
    byte t;
    ReadProcessMemory(hProcess,(void*)path,&timeaddr,4,NULL);
    ReadProcessMemory(hProcess,(void*)timeaddr,&t,1,NULL);
    if(t==0)
    {
        t=1;
    }
    else
    {
        t=0;
    }
    WriteProcessMemory(hProcess,(void*)timeaddr,(void*)&t,1,NULL);
    return 1;
}

int AddExtraSlots()
{
    int path=aobscan(hProcess,"C7 86 40 01 00 00 01 00 00 00 EB 08 33 D2",0);
    byte t[]= {0x90,0x90}; //74 0C
    WriteProcessMemory(hProcess,(void*)(path-2),(void*)&t[0],2,NULL);
    if(path<=0)
    {
        return 0;
    }
    byte ASM_CODE[]= {0xC7,0x86,0x40,0x01,0x00,0x00,0x02,0x00,0x00,0x00};
    inline_hook(hProcess,(void*)path+0x0E,6,ASM_CODE,sizeof(ASM_CODE));
    return 1;
}



int PumpkinMoon()
{
    void* Terraria_Main_startPumpkinMoon;
    SearchFunctionByName(L"Terraria.Main::startPumpkinMoon",&Terraria_Main_startPumpkinMoon,1);
    void* pmaddr;
    ReadProcessMemory(hProcess,Terraria_Main_startPumpkinMoon+0x8,&pmaddr,4,NULL);
    int t=0;
    ReadProcessMemory(hProcess,pmaddr,&t,1,NULL);
    t=t==0?1:0;
    WriteProcessMemory(hProcess,pmaddr,(void*)&t,1,NULL);
    return 1;
}

int SnowMoon()
{
    void* Terraria_Main_startPumpkinMoon;
    SearchFunctionByName(L"Terraria.Main::startPumpkinMoon",&Terraria_Main_startPumpkinMoon,1);
    void* smaddr;
    ReadProcessMemory(hProcess,Terraria_Main_startPumpkinMoon+0xf,&smaddr,4,NULL);
    int t=0;
    ReadProcessMemory(hProcess,smaddr,&t,1,NULL);
    t=t==0?1:0;
    WriteProcessMemory(hProcess,smaddr,(void*)&t,1,NULL);
    return 1;
}

int BloodMoon()
{
    void* Terraria_Main_startPumpkinMoon;
    SearchFunctionByName(L"Terraria.Main::startPumpkinMoon",&Terraria_Main_startPumpkinMoon,1);
    void* bmaddr;
    ReadProcessMemory(hProcess,Terraria_Main_startPumpkinMoon+0x16,&bmaddr,4,NULL);
    int t=0;
    ReadProcessMemory(hProcess,(void*)(bmaddr),&t,1,NULL);
    t=t==0?1:0;
    WriteProcessMemory(hProcess,(void*)bmaddr,(void*)&t,1,NULL);
    return 1;
}

int Eclipse()
{
    int path=aobscan(hProcess,"80 B8 83 01 00 00 00 74 15",0);
    if(path<=0)
    {
        return 0;
    }
    int bmaddr;
    ReadProcessMemory(hProcess,(void*)(path+0x48),&bmaddr,4,NULL);
    int t;
    ReadProcessMemory(hProcess,(void*)(bmaddr),&t,1,NULL);
    if(t==0)
    {
        t=1;
    }
    else
    {
        t=0;
    }
    WriteProcessMemory(hProcess,(void*)bmaddr,(void*)&t,1,NULL);
    return 1;
}

int SunDial()
{
    void* Terraria_Main_UpdateSundial;
    SearchFunctionByName(L"Terraria.Main::UpdateSundial",&Terraria_Main_UpdateSundial,1);
    void* saddr;
    ReadProcessMemory(hProcess,Terraria_Main_UpdateSundial+0x2,&saddr,4,NULL);
    int t=0;
    ReadProcessMemory(hProcess,(void*)(saddr),&t,1,NULL);
    t=t==0?1:0;
    WriteProcessMemory(hProcess,(void*)saddr,(void*)&t,1,NULL);
    return 1;
}


int GoldHoleDropBag()
{
    int path1=aobscan(hProcess,"8D 85 08 C7 FF FF D9 40 04",0);
    if(path1<=0)
    {
        return 0;
    }
    int path=path1-0x0c;
    byte b[30];
    int len=getHexCode("68 04 0D 00 00 6A 01 6A 00",b);
    inline_hook(hProcess,(void*)path,6,b,len);
    return 1;
}


int SlimeGunBurn()
{
    int path1=aobscan(hProcess,"8B 95 CC F3 FF FF 39 09 FF",0);
    if(path1<=0)
    {
        return 0;
    }
    int path=path1-0x0d;
    byte b[40];
    int len=getHexCode("68 c0 4b 03 00  6a 00  8b 8d 2c 94 ff ff  ba 99 00 00 00     90 39 09",b);///99 /2c
    WriteProcessMemory(hProcess,(void*)path,(void*)&b,len,NULL);
    return 1;
}


int NoPotionDelay()
{
    int path1=aobscan(hProcess,"89 90 70 04 00 00 8B 85 18 F1 FF FF",0);
    if(path1<=0)
    {
        return 0;
    }
    int path=path1-0x12;
    byte b[40];
    int len=getHexCode("C7 80 6C 04 00 00 00 00 00 00",b);
    inline_hook(hProcess,(void*)path,6,b,len);
    return 1;
}


int KillAllScreen()
{
    void *addr=(void*)malloc(4);
    SearchFunctionByName(L"Terraria.Player::ItemCheck",&addr,1);
    void *dst=addr+0x1e008;
    byte b[20];
    int len=getHexCode("90 90 90 90 90 90 90 90",b);
    WriteProcessMemory(hProcess,dst,b,len,NULL);
    return 1;
}




int FastTileSpeed()
{
    int path1=aobscan(hProcess,"8B 85 18 F1 FF FF D9 80 C4 03 00 00 D9 05",0);
    if(path1<=0)
    {
        return 0;
    }
    int path=path1-0x6;
    byte b[40];
    int len=getHexCode("D9 98 C8 03 00 00 C7 80 C8 03 00 00 00 00 80 3E",b);
    inline_hook(hProcess,(void*)path,6,b,len);
    return 1;
}


int De_FastTileSpeed()
{
    un_inline_hook(hProcess,"8B 85 18 F1 FF FF D9 80 C4 03 00 00 D9 05","D9 98 C8 03 00 00",0);
    return 1;
}



int RulerEffect()
{
    int path1=aobscan(hProcess,"88 96 f7 05 00 00 88 96 f8 05 00 00",0);
    if(path1<=0)
    {
        return 0;
    }
    int path=path1-6;
    byte b[40];
    int len=getHexCode("88 96 F6 05 00 00 C7 86 F6 05 00 00 01 00 00 00",b);
    inline_hook(hProcess,(void*)path,6,b,len);
    return 1;
}


int De_RulerEffect()
{
    un_inline_hook(hProcess,"88 96 F7 05 00 00 88 96 F8 05 00 00","88 96 F6 05 00 00",0);
    return 1;
}


int MachinicalRulerEffect()
{
    int path1=aobscan(hProcess,"88 96 F7 05 00 00 88 96 F8 05 00 00",0);
    if(path1<=0)
    {
        return 0;
    }
    int path=path1-6;
    byte b[40];
    int len=getHexCode("88 96 F6 05 00 00 C7 86 F6 05 00 00 01 00 00 00",b);
    inline_hook(hProcess,(void*)path,6,b,len);
    return 1;
}


int De_MachinicalRulerEffect()
{
    un_inline_hook(hProcess,"88 96 F7 05 00 00 88 96 F8 05 00 00","88 96 F6 05 00 00",0);
    return 1;
}


int InfernoEffect()
{
    int path1=aobscan(hProcess,"88 96 FF 04 00 00 88 96 00 05 00 00",0);
    if(path1<=0)
    {
        return 0;
    }
    int path=path1-6;
    byte b[40];
    int len=getHexCode("88 96 03 05 00 00 C7 86 03 05 00 00 01 00 00 00",b);
    inline_hook(hProcess,(void*)path,6,b,len);
    return 1;
}


int De_InfernoEffect()
{
    un_inline_hook(hProcess,"88 96 FF 04 00 00 88 96 00 05 00 00","88 96 03 05 00 00",0);
    return 1;
}


int ShadowDodge()
{
    int path1=aobscan(hProcess,"88 96 33 05 00 00 88 96 A9 05 00 00",0);
    if(path1<=0)
    {
        return 0;
    }
    int path=path1-6;
    byte b[40];
    int len=getHexCode("88 96 32 05 00 00 C7 86 32 05 00 00 01 00 00 00",b);
    inline_hook(hProcess,(void*)path,6,b,len);
    return 1;
}


int De_ShadowDodge()
{
    un_inline_hook(hProcess,"88 96 33 05 00 00 88 96 A9 05 00 00","88 96 32 05 00 00",0);
    return 1;
}


int ShowCircuit()
{
    int path1=aobscan(hProcess,"88 96 1D 06 00 00 88 96 1E 06 00 00",0);
    if(path1<=0)
    {
        return 0;
    }
    int path=path1-6;
    byte b[40];
    int len=getHexCode("88 96 2A 06 00 00 C7 86 2A 06 00 00 01 00 00 00",b);
    inline_hook(hProcess,(void*)path,6,b,len);
    return 1;
}

int De_ShowCircuit()
{
    un_inline_hook(hProcess,"88 96 1D 06 00 00 88 96 1E 06 00 00","88 96 2A 06 00 00",0);
    return 1;
}


int FishOnlyCrates()
{
    search_replace("0f 8d 4F 01 00 00 8b 45","90 90 90 90 90 90");
    return 1;
}

int De_FishOnlyCrates()
{
    search_replace("90 90 90 90 90 90 8B 45 A8 0B 45 A4","0f 8d 4F 01 00 00 8b 45");
    return 1;
}
//88 96 1C 06 00 00 88 96 1D 06 00 00
//88 96 29 06 00 00 C7 86 29 06 00 00 01 00 00 00



int De_InfiniteHealth()
{
    return search_replace("01 82 40 03 00 00","29 82 40 03 00 00");
}

int De_InfiniteMana()
{
    //search_replace("01 BE 44 03 00 00","29 BE 44 03 00 00");
    return search_replace("01 82 44 03 00 00","29 82 44 03 00 00");
}

int De_InfiniteItems()
{
    return search_replace("90 90 90 90 90 90 8B 45 08","FF 88 80 00 00 00 8B 45 08");
}

int De_InfiniteMinion()
{
    return search_replace("C7 86 14 02 00 00 FF FF FF FF","C7 86 14 02 00 00 01 00 00 00");
}

int De_InfiniteFly()
{
    return search_replace("90 90 90 90 90 90 5D C3 00","D9 99 20 02 00 00 5D C3 00");
}

int De_AwfulFishingSkill()
{
    return search_replace("83 83 00 02 00 00 64 E9 A1 3B 00 00","83 83 00 02 00 00 0F E9 A1 3B 00 00");
}

int De_GhostMode()
{
    char v=0;
    _Hack(getPlayerBaseAddress(getMyPlayer()),&v,1,1,0x549);
    return 0;
}

int De_InfiniteOxygen()
{
    return search_replace("90 90 90 90 90 90 83 B8 B4 02 00 00 00","FF 88 B4 02 00 00 83 B8 B4 02 00 00 00");
}

int De_InfiniteBullet()
{
    return search_replace("90 90 90 90 90 90 83 BB 80","FF 8B 80 00 00 00 83 BB 80");
}

int De_NoRespawnTime()
{
    return search_replace("C7 86 E8 02 00 00 00 00 00 00","C7 86 E8 02 00 00 58 02 00 00");
}

int De_AttackThroughWalls()
{
    return search_replace("E9 D5 03 00 00 90 8D 55","0F 85 D4 03 00 00 8D 55");
}

int De_ProjectileIgnoreTiles()
{
    void* Terraria_Projectile_HandleMovement;
    SearchFunctionByName(L"Terraria.Projectile::HandleMovement",&Terraria_Projectile_HandleMovement,1);
    int aAddr=(int)ceil((int)Terraria_Projectile_HandleMovement/0x10000)*0x10000;
    byte v=0x84;
    WriteProcessMemory(hProcess,(void*)aobscan(hProcess,"8d 7d d8",aAddr)-0x5,&v,1,NULL);
    return 1;
}

int De_JumpAsFeather()
{
    un_inline_hook(hProcess,"89 96 14 04 00 00","D9 9E 10 04 00 00",0);
    return 1;
}

int De_FastSpeed()
{
    un_inline_hook(hProcess,"88 96 4B 05 00 00 88 96 4D 05 00 00","D9 9E BC 03 00 00",0);
    return 1;
}

int De_KillAllNPC()
{
    un_inline_hook(hProcess,"8B 95 C4 B0 FF FF 3B 82 F8 00 00 00 0F 8C","8B 80 F4 00 00 00",0);
    return 1;
}

int De_GrabItemFarAway()
{
    int path=aobscan(hProcess,"80 BB 2E 06 00 00 00 90 90",0);
    byte b[256];
    char *aob="80 BB 2E 06 00 00 00 74 15 8B 51 6C 83 FA 47 7C 0D 83 FA 4A 7F 08";
    int len=getHexCode(aob,b);
    WriteProcessMemory(hProcess,(void*)path,(void*)&b[0],len,NULL);
    return 1;
}

int De_AddExtraSlots()
{
    int path=aobscan(hProcess,"C7 86 40 01 00 00 01 00 00 00 EB 08",0);
    byte t[]= {0x74,0x0c}; //74 0C
    WriteProcessMemory(hProcess,(void*)(path-2),(void*)&t[0],2,NULL);
    //un_inline_hook(hProcess,"C7 86 40 01 00 00 01 00 00 00 EB 08 33 D2","89 96 40 01 00 00",0x0e);
    int paddr;
    ReadProcessMemory(hProcess,(void*)(path+0x0f),&paddr,4,NULL);
    byte rb[10];
    getHexCode("89 96 40 01 00 00",rb);
    WriteProcessMemory(hProcess,(void*)(path+0x0e),(void*)&rb[0],6,NULL);
    VirtualFreeEx(hProcess,(void*)paddr,0,MEM_RELEASE);
    return 1;
}

int De_GoldHoleDropBag()
{
    un_inline_hook(hProcess,"8D 85 08 C7 FF FF D9 40 04","6A 49 6A 01 6A 00 6A 00 6A 00 6A 00",0);
    return 1;
}

int De_SlimeGunBurn()
{
    int path=aobscan(hProcess,"68 c0 4b 03 00 6a 00 8b 8d 2c 94 ff ff ba 2c 00 00 00 90 39 09",0);
    if(path<=0)
    {
        return 0;
    }
    byte b[40];
    int len=getHexCode("68 dc 05 00 00 6a 00 8b 8d 2c 94 ff ff 8b 95 cc f3 ff ff 39 09",b);
    WriteProcessMemory(hProcess,(void*)path,(void*)&b,len,NULL);
    return 1;
}



int De_NoPotionDelay()
{
    un_inline_hook(hProcess,"89 90 70 04 00 00 8B 85 18 F1 FF FF","89 90 6C 04 00 00",-12);
    return 1;
}

int De_KillAllScreen()
{
    void *addr=(void*)malloc(4);
    SearchFunctionByName(L"Terraria.Player::ItemCheck",&addr,1);
    void *dst=addr+0x1e008;
    byte b[20];
    int len=getHexCode("85 C0 0F 84 C5 14 00 00",b);
    WriteProcessMemory(hProcess,dst,b,len,NULL);
    return 1;
}




int getHealth()
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,1,0x340);
    return v;
}

void setHealth(int health)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&health,4,1,0x340);
}


int getMaxHealth()
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,1,0x338);
    return v;
}

void setMaxHealth(int health)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&health,4,1,0x338);
}

int getMana()
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,1,0x34c);
    return v;
}

void setMana(int mana)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&mana,4,1,0x34c);
}

int getMaxMana()
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,1,0x348);
    return v;
}

void setMaxMana(int mana)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&mana,4,1,0x348);
}



float getX()
{
    float v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,1,0x20);
    return v;
}

void setX(float X)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&X,4,1,0x20);
}

float getY()
{
    float v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,1,0x24);
    return v;
}

void setY(float Y)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&Y,4,1,0x24);
}



int HighLight()
{
    int path=aobscan(hProcess,"d9 46 08 d9 45 c4 df f1 dd d8 7a 0a 73 08 d9 46 08 d9 5d c4 eb 2c d9 45 c4 dd 05",0);
    if(path<=0)
    {
        return 0;
    }
    byte ASM_CODE[512];
    int len=getHexCode("C7 46 08 00 00 80 3F C7 46 10 00 00 80 3F C7 46 18 00 00 80 3F D9 46 08 D9 45 C4",ASM_CODE);

    inline_hook(hProcess,(void*)path,6,ASM_CODE,len);
    return 1;
    return 0;
}

int De_HighLight()
{
    un_inline_hook(hProcess,"df f1 dd d8 7a 0a 73 08 d9 46 08 d9 5d c4 eb 2c d9 45 c4 dd 05","d9 46 08 d9 45 c4",0);
    return 1;
}


int IgnoreRange()
{
    int path=aobscan(hProcess,"89 44 8A 08 41 3B",0);
    if(path<=0)
    {
        return 0;
    }
    int t1=path+0x1A;
    int t2=path+0x24;
    int v=999;
    WriteProcessMemory(hProcess,(void*)t1,(void*)&v,4,NULL);
    WriteProcessMemory(hProcess,(void*)t2,(void*)&v,4,NULL);
    return 1;
    return 0;
}

int De_IgnoreRange()
{
    int path=aobscan(hProcess,"89 44 8A 08 41 3B",0);
    if(path<=0)
    {
        return 0;
    }
    int t1=path+0x1A;
    int t2=path+0x24;
    int v1=5;
    int v2=4;
    WriteProcessMemory(hProcess,(void*)t1,(void*)&v1,4,NULL);
    WriteProcessMemory(hProcess,(void*)t2,(void*)&v2,4,NULL);
    return 1;
}

byte getPlayerActive(int pid)
{
    byte v;
    _Read_FromBase(playerarrbase,&v,1,2,0x08+pid*0x04,0x18);
    return v;
}

int getPlayerBuffType(int pid,int id)
{
    int v;
    _Read_FromBase(playerarrbase,&v,4,3,0x08+pid*0x04,0xac,0x08+id*0x04);
    return v;
}


int getPlayerBuffTime(int pid,int id)
{
    int v;
    _Read_FromBase(playerarrbase,&v,4,3,0x08+pid*0x04,0xb0,0x08+id*0x04);
    return v;
}

int getBuffType(int id)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,2,0xac,0x08+id*0x04);
    return v;
}

void setBuffType(int id,int type)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&type,4,2,0xac,0x08+id*0x04);
}

int getBuffTime(int id)
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,2,0xb0,0x08+id*0x04);
    return v;
}

void setBuffTime(int id,int time)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&time,4,2,0xb0,0x08+id*0x04);
}


void* InitEax(int pid)
{
    void* r;
    int f=aobscan(hProcess,"8B 44 90 08 80 B8 E2 05 00 00 00 74 08",0);//Terraria.Lighting::LightTiles+13B - 8B 44 90 08
    if(f<=0)
        return 0;
    f-=0x13;
    int q;
    ReadProcessMemory(hProcess,(void*)f,&q,4,NULL);
    ReadProcessMemory(hProcess,(void*)q,&r,4,NULL);
    playerarrbase=r;
    /*char *p=(char*)malloc(20);
    itoa(playerarrbase,p,16);
    MessageBoxA(NULL,p,p,MB_OK);*/
    return playerarrbase;
}



wchar_t *getPlayerName(int id,int *len)
{
    setlocale(LC_ALL, "");
    wchar_t *c=(wchar_t*)malloc(40);
    memset(c,0,40);
    _Read_FromBase(playerarrbase,c,40,3,0x08+id*0x04,0x70,0x08);
    *len=wcslen(c);
    return c;
}


float getPlayerX(int id)
{
    float v;
    _Read_FromBase(playerarrbase,&v,4,2,0x08+id*0x04,0x20);
    return v;
}


float getPlayerY(int id)
{
    float v;
    _Read_FromBase(playerarrbase,&v,4,2,0x08+id*0x04,0x24);
    return v;
}


int getPlayerHealth(int id)
{
    int v;
    _Read_FromBase(playerarrbase,&v,4,2,0x08+id*0x04,0x340);
    return v;
}


int getPlayerMaxHealth(int id)
{
    int v;
    _Read_FromBase(playerarrbase,&v,4,2,0x08+id*0x04,0x338);
    return v;
}


int getPlayerItemBase(int id)
{
    int v;
    _Read_FromBase(playerarrbase,&v,4,2,0x08+id*0x04,0xbc);
    return v;
}

void setPlayerItemBase(int id,int ibase)
{
    _Hack(playerarrbase,&ibase,4,2,0x08+id*0x04,0xbc);
}

int getMyPlayer()
{
    void *addr;
    SearchFunctionByName(L"Terraria.Main::ReverseGravitySupport",&addr,1);
    addr+=0xb;
    void *addr1;
    ReadProcessMemory(hProcess,addr,&addr1,4,NULL);
    int target;
    ReadProcessMemory(hProcess,addr1,&target,4,NULL);
    return target;
}

void setMyPlayer(int index)
{
    void *addr;
    SearchFunctionByName(L"Terraria.Main::ReverseGravitySupport",&addr,1);
    addr+=0xb;
    void *addr1;
    ReadProcessMemory(hProcess,addr,&addr1,4,NULL);
    WriteProcessMemory(hProcess,addr1,&index,4,NULL);
}

void* getPlayerBaseAddress(int player)
{
    /*char str[20];
    sprintf(str,"%d",player);
    MessageBox(0,str,str,MB_OK);*/
    void *addr;
    _Read_FromBase(playerarrbase,&addr,4,1,0x8+0x4*player);
    return addr;
}

int getPlayerItem(int id,int slot)
{
    int v;
    _Read_FromBase(playerarrbase,&v,4,4,0x08+id*0x04,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.type);
    return v;
}


int getPlayerItemNum(int id,int slot)
{
    int v;
    _Read_FromBase(playerarrbase,&v,4,4,0x08+id*0x04,itemArrOff,0x08+slot*0x04,OFFSET_ITEM.stack);
    return v;
}

int getDropedItemID(int index)
{
    int val;
    _Read_FromBase(dropeditembase,&val,4,2,0x08+index*0x04,OFFSET_ITEM.type);
    return val;
}


void setDropedItemID(int index,int id)
{
    _Hack(dropeditembase,&id,4,2,0x08+index*0x04,OFFSET_ITEM.type);
    _Hack(dropeditembase,&id,4,2,0x08+index*0x04,OFFSET_ITEM.type+0xA0);
}


float getDropedItemX(int index)
{
    float val;
    _Read_FromBase(dropeditembase,&val,4,2,0x08+index*0x04,0x20);
    return val;
}


void setDropedItemX(int index,float X)
{
    _Hack(dropeditembase,&X,4,2,0x08+index*0x04,0x20);
}

float getDropedItemY(int index)
{
    float val;
    _Read_FromBase(dropeditembase,&val,4,2,0x08+index*0x04,0x24);
    return val;
}


void setDropedItemY(int index,float Y)
{
    _Hack(dropeditembase,&Y,4,2,0x08+index*0x04,0x24);
}


int getDropedItemCount(int index)
{
    int val;
    _Read_FromBase(dropeditembase,&val,4,2,0x08+index*0x04,OFFSET_ITEM.stack);
    return val;
}


void setDropedItemCount(int index,int count)
{
    _Hack(dropeditembase,&count,4,2,0x08+index*0x04,OFFSET_ITEM.stack);
}

void FreeMemory(void *v)
{
    free(v);
}

int getMaxTilesX()
{
    void* f,*r;
    int t;
    SearchFunctionByName(L"Terraria.DelegateMethods::TestDust",&f,1);
    f+=0xd;

    ReadProcessMemory(hProcess,f,&r,4,NULL);
    ReadProcessMemory(hProcess,r,&t,4,NULL);
    return t;
}

int getMaxTilesY()
{
    void* f,*r;
    int t;
    SearchFunctionByName(L"Terraria.DelegateMethods::TestDust",&f,1);
    f+=0x19;

    ReadProcessMemory(hProcess,f,&r,4,NULL);
    ReadProcessMemory(hProcess,r,&t,4,NULL);
    return t;
}

void* getMain_Map()
{
    void* f,*r;
    f=(void*)aobscan(hProcess,"0F 8C 84 FE FF FF 43",0);
    f-=0x15;

    ReadProcessMemory(hProcess,f,&r,4,NULL);
    return r;
}

void UpdateLighting(int x,int y,byte light)
{
    void* addr=getMain_Map();
    byte b[500],raw_code[7];
    ReadProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
    ///mov flag,0
    ///push ecx
    ///push edx
    ///push eax
    ///push ebx
    ///mov ecx,Map
    ///mov edx,X
    ///push Y
    ///push light
    ///call Terraria.Map.WorldMap::UpdateLighting
    ///pop ebx
    ///pop eax
    ///pop edx
    ///pop ecx
    ///xxxx
    ///mov flag,1
    ///jmp back
    int blen=getHexCode("C7 05 00 00 00 00 00 00 00 00\
                        51\
                        52\
                        50\
                        53\
                        8B 0D 00 00 00 00\
                        BA 00 00 00 00\
                        68 00 00 00 00\
                        6A 00\
                        E8 00 00 00 00\
                        5B\
                        58\
                        5A\
                        59\
                        00 00 00000000 00\
                        C7 05 00 00 00 00 01 00 00 00\
                        E9 00 00 00 00",
                        b);
    void* hookAddr=VirtualAllocEx(hProcess, NULL, blen, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    void* flagAddr=VirtualAllocEx(hProcess, NULL, 4, MEM_COMMIT, PAGE_READWRITE);
    int *d_flag1=(int*)&b[2];
    int *d_Map=(int*)&b[16];
    int *d_X=(int*)&b[21];
    int *d_Y=(int*)&b[26];
    byte *d_light=(byte*)&b[31];
    int *d_jmpUpdateLighting=(int*)&b[33];
    int *d_code=(int*)&b[41];
    int *d_flag2=(int*)&b[50];
    int *d_jmpRet=(int*)&b[blen-4];
    *d_flag1=(int)flagAddr;
    *d_Map=(int)addr;
    *d_X=x;
    *d_Y=y;
    *d_light=light;
    *d_jmpUpdateLighting=Terraria_Map_WorldMap_UpdateLighting-(hookAddr+33)-4;
    memcpy(d_code,raw_code,7);
    *d_flag2=(int)flagAddr;
    *d_jmpRet=(Terraria_Main_Update+0x2B)-(hookAddr+blen-4)+3;
    byte jmpCode[5];
    jmpCode[0]=0xe9;
    *((int*)&jmpCode[1])=hookAddr-(Terraria_Main_Update+0x2B)-5;
    WriteProcessMemory(hProcess,hookAddr,b,blen,NULL);
    WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,jmpCode,5,NULL);
    while(1)
    {
        int flag=0;
        ReadProcessMemory(hProcess,flagAddr,&flag,4,NULL);
        if(flag==1)
            break;
    }
    WriteProcessMemory(hProcess,Terraria_Main_Update+0x2B,raw_code,7,NULL);
    VirtualFreeEx(hProcess,(void*)hookAddr,0,MEM_RELEASE);
    VirtualFreeEx(hProcess,(void*)flagAddr,0,MEM_RELEASE);
}

void RefreshMap()
{

    void *t,*r;
    byte f=1;
    t=(void*)aobscan(hProcess,"E9 CF 00 00 00 8B D8 B9",0);
    t-=0x18;
    ReadProcessMemory(hProcess,t,&r,4,NULL);
    WriteProcessMemory(hProcess,r,&f,4,NULL);
}

int getSelectedItem()
{
    int v;
    _Read_FromBase(getPlayerBaseAddress(getMyPlayer()),&v,4,1,0x280);
    return v;
}

void setSelectedItem(int si)
{
    _Hack(getPlayerBaseAddress(getMyPlayer()),&si,4,1,0x280);
}

int BlockAttacking()
{
    return search_replace("80 7C 02 08 00 0F 84 DA 02 00 00 83 BD","80 7C 02 08 FF");
}

int De_BlockAttacking()
{
    return search_replace("80 7C 02 08 FF 0F 84 DA 02 00 00 83 BD","80 7C 02 08 00");
}

