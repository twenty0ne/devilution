#include "diablo.h"

int cursH;      // weak
int icursH28;   // idb
int cursW;      // idb
int pcursmonst; // idb
int icursW28;   // idb
void *pCursCels;
int icursH; // weak

// inv_item value
char pcursinvitem; // weak
int icursW;        // weak
char pcursitem;    // weak
char pcursobj;     // weak
char pcursplr;     // weak
int cursmx; // 鼠标转换到地图 x
int cursmy; // 鼠标转到到地图 y
int pcurstemp; // weak
int pcurs;        // idb

/* rdata */
const int InvItemWidth[180] = {
	// Cursors
	0, 33, 32, 32, 32, 32, 32, 32, 32, 32, 32, 23,
	// Items
	1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28,
	1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28,
	1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28,
	1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28,
	1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28,
	1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28,
	1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28,
	1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28,
	2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28,
	2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28,
	2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28,
	2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28,
	2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28,
	2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28,
	2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28,
	2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28,
	2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28
};

const int InvItemHeight[180] = {
	// Cursors
	0, 29, 32, 32, 32, 32, 32, 32, 32, 32, 32, 35,
	// Items
	1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28,
	1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28,
	1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28,
	1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28,
	1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28, 1 * 28,
	2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28,
	3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28,
	3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28,
	2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28,
	2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28, 2 * 28,
	3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28,
	3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28,
	3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28,
	3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28,
	3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28,
	3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28,
	3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28, 3 * 28
};

void InitCursor()
{
	/// ASSERT: assert(! pCursCels);
	pCursCels = LoadFileInMem("Data\\Inv\\Objcurs.CEL", 0);
	ClearCursor();
}

void FreeCursor()
{
	MemFreeDbg(pCursCels);
	ClearCursor();
}

void SetICursor(int i)
{
	icursW = InvItemWidth[i];
	icursH = InvItemHeight[i];
	icursW28 = icursW / 28;
	icursH28 = icursH / 28;
}

void SetCursor_(int i)
{
	pcurs = i;
	cursW = InvItemWidth[i];
	cursH = InvItemHeight[i];
	SetICursor(i);
}

void NewCursor(int i)
{
	SetCursor_(i);
}

void InitLevelCursor()
{
	SetCursor_(CURSOR_HAND);
	cursmx = ViewX;
	cursmy = ViewY;
	pcurstemp = -1;
	pcursmonst = -1;
	pcursobj = -1;
	pcursitem = -1;
	pcursplr = -1;
	ClearCursor();
}

void CheckTown()
{
	int i, mx;

	for (i = 0; i < nummissiles; i++) {
		mx = missileactive[i];
		if (missile[mx]._mitype == MIS_TOWN) {
			if (cursmx == missile[mx]._mix - 1 && cursmy == missile[mx]._miy
			    || cursmx == missile[mx]._mix && cursmy == missile[mx]._miy - 1
			    || cursmx == missile[mx]._mix - 1 && cursmy == missile[mx]._miy - 1
			    || cursmx == missile[mx]._mix - 2 && cursmy == missile[mx]._miy - 1
			    || cursmx == missile[mx]._mix - 2 && cursmy == missile[mx]._miy - 2
			    || cursmx == missile[mx]._mix - 1 && cursmy == missile[mx]._miy - 2
			    || cursmx == missile[mx]._mix && cursmy == missile[mx]._miy) {
				trigflag = TRUE;
				ClearPanel();
				strcpy(infostr, "Town Portal");
				sprintf(tempstr, "from %s", plr[missile[mx]._misource]._pName);
				AddPanelString(tempstr, 1);
				cursmx = missile[mx]._mix;
				cursmy = missile[mx]._miy;
			}
		}
	}
}

void CheckRportal()
{
	int i, mx;

	for (i = 0; i < nummissiles; i++) {
		mx = missileactive[i];
		if (missile[mx]._mitype == MIS_RPORTAL) {
			if (cursmx == missile[mx]._mix - 1 && cursmy == missile[mx]._miy
			    || cursmx == missile[mx]._mix && cursmy == missile[mx]._miy - 1
			    || cursmx == missile[mx]._mix - 1 && cursmy == missile[mx]._miy - 1
			    || cursmx == missile[mx]._mix - 2 && cursmy == missile[mx]._miy - 1
			    || cursmx == missile[mx]._mix - 2 && cursmy == missile[mx]._miy - 2
			    || cursmx == missile[mx]._mix - 1 && cursmy == missile[mx]._miy - 2
			    || cursmx == missile[mx]._mix && cursmy == missile[mx]._miy) {
				trigflag = TRUE;
				ClearPanel();
				strcpy(infostr, "Portal to");
				if (!setlevel)
					strcpy(tempstr, "The Unholy Altar");
				else
					strcpy(tempstr, "level 15");
				AddPanelString(tempstr, 1);
				cursmx = missile[mx]._mix;
				cursmy = missile[mx]._miy;
			}
		}
	}
}

void CheckCursMove()
{
	int i, sx, sy, mx, my, tx, ty, px, py, xx, yy, mi;
	char bv;
	BOOL flipflag, flipx, flipy;

	sx = MouseX;
	sy = MouseY;

	// 根据 flag 限定范围
	if(chrflag || questlog) {
		if(sx >= 160) {
			sx -= 160;
		} else {
			sx = 0;
		}
	} else if(invflag || sbookflag) {
		if(sx <= 320) {
			sx += 160;
		} else {
			sx = 0;
		}
	}
	if(sy > 351 && track_isscrolling()) {
		sy = 351;
	}
	if(!zoomflag) {
		sx >>= 1;
		sy >>= 1;
	}

	// TODO:
	// ? 
	sx -= ScrollInfo._sxoff;
	sy -= ScrollInfo._syoff;

	if(ScrollInfo._sdir != 0) {
		sx += ((plr[myplr]._pVar6 + plr[myplr]._pxvel) >> 8) - (plr[myplr]._pVar6 >> 8);
		sy += ((plr[myplr]._pVar7 + plr[myplr]._pyvel) >> 8) - (plr[myplr]._pVar7 >> 8);
	}

	if(sx < 0) {
		sx = 0;
	}
	if(sx >= 640) {
		sx = 640;
	}
	if(sy < 0) {
		sy = 0;
	}
	if(sy >= 480) {
		sy = 480;
	}

	// 转化到 tile 位置
	// tx 是商, px 是余数
	// 比如 sx = 64, tx = 1, px = 0
	tx = sx >> 6; // sx / 64 = (0, 10)
	ty = sy >> 5; // sy / 32 = (0, 15)
	px = sx & 0x3F;
	py = sy & 0x1F;
	// TODO:
	// ?
	mx = ViewX + tx + ty - (zoomflag ? 10 : 5);
	my = ViewY + ty - tx;

	flipy = py < px >> 1;
	if(flipy) {
		my--;
	}
	flipx = py >= 32 - (px >> 1);
	if(flipx) {
		mx++;
	}

	if(mx < 0) {
		mx = 0;
	}
	// MAXDUNX - 地牢的宽度
	if(mx >= MAXDUNX) {
		mx = MAXDUNX - 1;
	}
	if(my < 0) {
		my = 0;
	}
	if(my >= MAXDUNY) {
		my = MAXDUNY - 1;
	}

	flipflag = flipy && flipx || (flipy || flipx) && px < 32;

	pcurstemp = pcursmonst;
	pcursmonst = -1;
	pcursobj = -1;
	pcursitem = -1;
	if(pcursinvitem != -1) {
		drawsbarflag = TRUE;
	}
	pcursinvitem = -1;
	pcursplr = -1;
	uitemflag = 0;
	panelflag = 0;
	trigflag = FALSE;

	if(plr[myplr]._pInvincible) {
		return;
	}
	if(pcurs >= CURSOR_FIRSTITEM || spselflag) {
		cursmx = mx;
		cursmy = my;
		return;
	}
	if(MouseY > 352) {
		CheckPanelInfo();
		return;
	}
	if(doomflag) {
		return;
	}
	if(invflag && MouseX > 320) {
		pcursinvitem = CheckInvHLight();
		return;
	}
	if(sbookflag && MouseX > 320) {
		return;
	}
	if((chrflag || questlog) && MouseX < 320) {
		return;
	}

	// TODO:
	// mx, my 是如何计算的, 是否是玩家面向的方向
	// 首先检查是否指向 monster
	if(leveltype != DTYPE_TOWN) {
		// 如果上一次选中了 monster ，优先判断这次选中的还是不是他
		if(pcurstemp != -1) {
			if(!flipflag && dMonster[mx + 2][my + 1] != 0 && dFlags[mx + 2][my + 1] & DFLAG_LIT) {
				mi = dMonster[mx + 2][my + 1] > 0 ? dMonster[mx + 2][my + 1] - 1 : -(dMonster[mx + 2][my + 1] + 1);
				if(mi == pcurstemp && monster[mi]._mhitpoints >> 6 > 0 && monster[mi].MData->mSelFlag & 4) {
					cursmx = mx + 1; /// BUGFIX: 'mx + 2'
					cursmy = my + 2; /// BUGFIX: 'my + 1'
					pcursmonst = mi;
				}
			}
			if(flipflag && dMonster[mx + 1][my + 2] != 0 && dFlags[mx + 1][my + 2] & DFLAG_LIT) {
				mi = dMonster[mx + 1][my + 2] > 0 ? dMonster[mx + 1][my + 2] - 1 : -(dMonster[mx + 1][my + 2] + 1);
				if(mi == pcurstemp && monster[mi]._mhitpoints >> 6 > 0 && monster[mi].MData->mSelFlag & 4) {
					cursmx = mx + 1;
					cursmy = my + 2;
					pcursmonst = mi;
				}
			}
			if(dMonster[mx + 2][my + 2] != 0 && dFlags[mx + 2][my + 2] & DFLAG_LIT) {
				mi = dMonster[mx + 2][my + 2] > 0 ? dMonster[mx + 2][my + 2] - 1 : -(dMonster[mx + 2][my + 2] + 1);
				if(mi == pcurstemp && monster[mi]._mhitpoints >> 6 > 0 && monster[mi].MData->mSelFlag & 4) {
					cursmx = mx + 2;
					cursmy = my + 2;
					pcursmonst = mi;
				}
			}
			if(!flipflag && dMonster[mx + 1][my] != 0 && dFlags[mx + 1][my] & DFLAG_LIT) {
				mi = dMonster[mx + 1][my] > 0 ? dMonster[mx + 1][my] - 1 : -(dMonster[mx + 1][my] + 1);
				if(mi == pcurstemp && monster[mi]._mhitpoints >> 6 > 0 && monster[mi].MData->mSelFlag & 2) {
					cursmx = mx + 1;
					cursmy = my;
					pcursmonst = mi;
				}
			}
			if(flipflag && dMonster[mx][my + 1] != 0 && dFlags[mx][my + 1] & DFLAG_LIT) {
				mi = dMonster[mx][my + 1] > 0 ? dMonster[mx][my + 1] - 1 : -(dMonster[mx][my + 1] + 1);
				if(mi == pcurstemp && monster[mi]._mhitpoints >> 6 > 0 && monster[mi].MData->mSelFlag & 2) {
					cursmx = mx;
					cursmy = my + 1;
					pcursmonst = mi;
				}
			}
			if(dMonster[mx][my] != 0 && dFlags[mx][my] & DFLAG_LIT) {
				mi = dMonster[mx][my] > 0 ? dMonster[mx][my] - 1 : -(dMonster[mx][my] + 1);
				if(mi == pcurstemp && monster[mi]._mhitpoints >> 6 > 0 && monster[mi].MData->mSelFlag & 1) {
					cursmx = mx;
					cursmy = my;
					pcursmonst = mi;
				}
			}
			if(dMonster[mx + 1][my + 1] != 0 && dFlags[mx + 1][my + 1] & DFLAG_LIT) {
				mi = dMonster[mx + 1][my + 1] > 0 ? dMonster[mx + 1][my + 1] - 1 : -(dMonster[mx + 1][my + 1] + 1);
				if(mi == pcurstemp && monster[mi]._mhitpoints >> 6 > 0 && monster[mi].MData->mSelFlag & 2) {
					cursmx = mx + 1;
					cursmy = my + 1;
					pcursmonst = mi;
				}
			}
			if(pcursmonst != -1 && monster[pcursmonst]._mFlags & MFLAG_HIDDEN) {
				pcursmonst = -1;
				cursmx = mx;
				cursmy = my;
			}
			if(pcursmonst != -1 && monster[pcursmonst]._mFlags & MFLAG_GOLEM) {
				pcursmonst = -1;
			}
			if(pcursmonst != -1) {
				return;
			}
		}
		// 如果上一次没有选中 monster
		if(!flipflag && dMonster[mx + 2][my + 1] != 0 && dFlags[mx + 2][my + 1] & DFLAG_LIT) {
			mi = dMonster[mx + 2][my + 1] > 0 ? dMonster[mx + 2][my + 1] - 1 : -(dMonster[mx + 2][my + 1] + 1);
			if(monster[mi]._mhitpoints >> 6 > 0 && monster[mi].MData->mSelFlag & 4) {
				cursmx = mx + 2;
				cursmy = my + 1;
				pcursmonst = mi;
			}
		}
		if(flipflag && dMonster[mx + 1][my + 2] != 0 && dFlags[mx + 1][my + 2] & DFLAG_LIT) {
			mi = dMonster[mx + 1][my + 2] > 0 ? dMonster[mx + 1][my + 2] - 1 : -(dMonster[mx + 1][my + 2] + 1);
			if(monster[mi]._mhitpoints >> 6 > 0 && monster[mi].MData->mSelFlag & 4) {
				cursmx = mx + 1;
				cursmy = my + 2;
				pcursmonst = mi;
			}
		}
		if(dMonster[mx + 2][my + 2] != 0 && dFlags[mx + 2][my + 2] & DFLAG_LIT) {
			mi = dMonster[mx + 2][my + 2] > 0 ? dMonster[mx + 2][my + 2] - 1 : -(dMonster[mx + 2][my + 2] + 1);
			if(monster[mi]._mhitpoints >> 6 > 0 && monster[mi].MData->mSelFlag & 4) {
				cursmx = mx + 2;
				cursmy = my + 2;
				pcursmonst = mi;
			}
		}
		if(!flipflag && dMonster[mx + 1][my] != 0 && dFlags[mx + 1][my] & DFLAG_LIT) {
			mi = dMonster[mx + 1][my] > 0 ? dMonster[mx + 1][my] - 1 : -(dMonster[mx + 1][my] + 1);
			if(monster[mi]._mhitpoints >> 6 > 0 && monster[mi].MData->mSelFlag & 2) {
				cursmx = mx + 1;
				cursmy = my;
				pcursmonst = mi;
			}
		}
		if(flipflag && dMonster[mx][my + 1] != 0 && dFlags[mx][my + 1] & DFLAG_LIT) {
			mi = dMonster[mx][my + 1] > 0 ? dMonster[mx][my + 1] - 1 : -(dMonster[mx][my + 1] + 1);
			if(monster[mi]._mhitpoints >> 6 > 0 && monster[mi].MData->mSelFlag & 2) {
				cursmx = mx;
				cursmy = my + 1;
				pcursmonst = mi;
			}
		}
		if(dMonster[mx][my] != 0 && dFlags[mx][my] & DFLAG_LIT) {
			mi = dMonster[mx][my] > 0 ? dMonster[mx][my] - 1 : -(dMonster[mx][my] + 1);
			if(monster[mi]._mhitpoints >> 6 > 0 && monster[mi].MData->mSelFlag & 1) {
				cursmx = mx;
				cursmy = my;
				pcursmonst = mi;
			}
		}
		if(dMonster[mx + 1][my + 1] != 0 && dFlags[mx + 1][my + 1] & DFLAG_LIT) {
			mi = dMonster[mx + 1][my + 1] > 0 ? dMonster[mx + 1][my + 1] - 1 : -(dMonster[mx + 1][my + 1] + 1);
			if(monster[mi]._mhitpoints >> 6 > 0 && monster[mi].MData->mSelFlag & 2) {
				cursmx = mx + 1;
				cursmy = my + 1;
				pcursmonst = mi;
			}
		}
		if(pcursmonst != -1 && monster[pcursmonst]._mFlags & MFLAG_HIDDEN) {
			pcursmonst = -1;
			cursmx = mx;
			cursmy = my;
		}
		if(pcursmonst != -1 && monster[pcursmonst]._mFlags & MFLAG_GOLEM) {
			pcursmonst = -1;
		}
	} else {
		if(!flipflag && dMonster[mx + 1][my] > 0) {
			pcursmonst = dMonster[mx + 1][my] - 1;
			cursmx = mx + 1;
			cursmy = my;
		}
		if(flipflag && dMonster[mx][my + 1] > 0) {
			pcursmonst = dMonster[mx][my + 1] - 1;
			cursmx = mx;
			cursmy = my + 1;
		}
		if(dMonster[mx][my] > 0) {
			pcursmonst = dMonster[mx][my] - 1;
			cursmx = mx;
			cursmy = my;
		}
		if(dMonster[mx + 1][my + 1] > 0) {
			pcursmonst = dMonster[mx + 1][my + 1] - 1;
			cursmx = mx + 1;
			cursmy = my + 1;
		}
		if(!towner[pcursmonst]._tSelFlag) { /// BUGFIX: Add check 'pcursmonst != -1'
			pcursmonst = -1;
		}
	}

	// 判断是否选中其他 player
	if(pcursmonst == -1) {
		if(!flipflag && dPlayer[mx + 1][my] != 0) {
			bv = dPlayer[mx + 1][my] > 0 ? dPlayer[mx + 1][my] - 1 : -(dPlayer[mx + 1][my] + 1);
			if(bv != myplr && plr[bv]._pHitPoints != 0) {
				cursmx = mx + 1;
				cursmy = my;
				pcursplr = bv;
			}
		}
		if(flipflag && dPlayer[mx][my + 1] != 0) {
			bv = dPlayer[mx][my + 1] > 0 ? dPlayer[mx][my + 1] - 1 : -(dPlayer[mx][my + 1] + 1);
			if(bv != myplr && plr[bv]._pHitPoints != 0) {
				cursmx = mx;
				cursmy = my + 1;
				pcursplr = bv;
			}
		}
		if(dPlayer[mx][my] != 0) {
			bv = dPlayer[mx][my] > 0 ? dPlayer[mx][my] - 1 : -(dPlayer[mx][my] + 1);
			if(bv != myplr) {
				cursmx = mx;
				cursmy = my;
				pcursplr = bv;
			}
		}
		// 如果选中了死亡的 玩家
		if(dFlags[mx][my] & DFLAG_DEAD_PLAYER) {
			for(i = 0; i < MAX_PLRS; i++) {
				if(plr[i].WorldX == mx && plr[i].WorldY == my && i != myplr) {
					cursmx = mx;
					cursmy = my;
					pcursplr = i;
				}
			}
		}
		// 如果使用复活
		if(pcurs == CURSOR_RESURRECT) {
			for(xx = -1; xx < 2; xx++) {
				for(yy = -1; yy < 2; yy++) {
					if(dFlags[mx + xx][my + yy] & DFLAG_DEAD_PLAYER) {
						for(i = 0; i < MAX_PLRS; i++) {
							if(plr[i].WorldX == mx + xx && plr[i].WorldY == my + yy && i != myplr) {
								cursmx = mx + xx;
								cursmy = my + yy;
								pcursplr = i;
							}
						}
					}
				}
			}
		}
		if(dPlayer[mx + 1][my + 1] != 0) {
			bv = dPlayer[mx + 1][my + 1] > 0 ? dPlayer[mx + 1][my + 1] - 1 : -(dPlayer[mx + 1][my + 1] + 1);
			if(bv != myplr && plr[bv]._pHitPoints != 0) {
				cursmx = mx + 1;
				cursmy = my + 1;
				pcursplr = bv;
			}
		}
	}
	// 判断是否选中 object
	if(pcursmonst == -1 && pcursplr == -1) {
		if(!flipflag && dObject[mx + 1][my] != 0) {
			bv = dObject[mx + 1][my] > 0 ? dObject[mx + 1][my] - 1 : -(dObject[mx + 1][my] + 1);
			if(object[bv]._oSelFlag >= 2) {
				cursmx = mx + 1;
				cursmy = my;
				pcursobj = bv;
			}
		}
		if(flipflag && dObject[mx][my + 1] != 0) {
			bv = dObject[mx][my + 1] > 0 ? dObject[mx][my + 1] - 1 : -(dObject[mx][my + 1] + 1);
			if(object[bv]._oSelFlag >= 2) {
				cursmx = mx;
				cursmy = my + 1;
				pcursobj = bv;
			}
		}
		if(dObject[mx][my] != 0) {
			bv = dObject[mx][my] > 0 ? dObject[mx][my] - 1 : -(dObject[mx][my] + 1);
			if(object[bv]._oSelFlag == 1 || object[bv]._oSelFlag == 3) {
				cursmx = mx;
				cursmy = my;
				pcursobj = bv;
			}
		}
		if(dObject[mx + 1][my + 1] != 0) {
			bv = dObject[mx + 1][my + 1] > 0 ? dObject[mx + 1][my + 1] - 1 : -(dObject[mx + 1][my + 1] + 1);
			if(object[bv]._oSelFlag >= 2) {
				cursmx = mx + 1;
				cursmy = my + 1;
				pcursobj = bv;
			}
		}
	}
	// 判断是否选中 item
	if(pcursplr == -1 && pcursobj == -1 && pcursmonst == -1) {
		if(!flipflag && dItem[mx + 1][my] > 0) {
			bv = dItem[mx + 1][my] - 1;
			if(item[bv]._iSelFlag >= 2) {
				cursmx = mx + 1;
				cursmy = my;
				pcursitem = bv;
			}
		}
		if(flipflag && dItem[mx][my + 1] > 0) {
			bv = dItem[mx][my + 1] - 1;
			if(item[bv]._iSelFlag >= 2) {
				cursmx = mx;
				cursmy = my + 1;
				pcursitem = bv;
			}
		}
		if(dItem[mx][my] > 0) {
			bv = dItem[mx][my] - 1;
			if(item[bv]._iSelFlag == 1 || item[bv]._iSelFlag == 3) {
				cursmx = mx;
				cursmy = my;
				pcursitem = bv;
			}
		}
		if(dItem[mx + 1][my + 1] > 0) {
			bv = dItem[mx + 1][my + 1] - 1;
			if(item[bv]._iSelFlag >= 2) {
				cursmx = mx + 1;
				cursmy = my + 1;
				pcursitem = bv;
			}
		}
		if(pcursitem == -1) {
			cursmx = mx;
			cursmy = my;
			CheckTrigForce();
			CheckTown();
			CheckRportal();
		}
	}

	if(pcurs == CURSOR_IDENTIFY) {
		pcursobj = -1;
		pcursmonst = -1;
		pcursitem = -1;
		cursmx = mx;
		cursmy = my;
	}
	if(pcursmonst != -1 && monster[pcursmonst]._mFlags & MFLAG_GOLEM) {
		pcursmonst = -1;
	}
}
