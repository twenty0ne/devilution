函数访问性
大写是public
小写是private

diablo.cpp
>StartGame
>run_game_loop
>game_logic

SyncPlrKill -> StartPlayerKill -> CMD_PLRDEAD

ProcessPlayers
PM_DoWalk

PM_WALK:
plr[pnum]._pVar1 = xadd; // 1 or -1
plr[pnum]._pVar2 = yadd; // 1 or -1
plr[pnum]._pVar3 = EndDir; // DIR_W or DIR_E ...

MODE 和 ACTION 是不冲突的
比如要执行 ACTION_PICKUPITEM
PM_WALK 并不会打断

NetSendCmdXXX
这块如何处理发往自己的消息

CheckNewPath:
同样回去更新 pmode / PM_STAND, PM_WALK

MakePlrPath:
更新玩家寻路路径

操作：
LeftMouseCmd
CheckCursMove - 更新鼠标移动位置

diablo.GM_Game 是获取输入

CheckCursMove 判断选中的顺序：monster > player > object > item

主要的网络请求
SNetSendMessage
SNetReceiveMessage

网络建主流程：
> NetInit 
> plr[myplr].plractive = TRUE 
> 

TODO:
Q: plr.px/py WorldX, WorldY 有什么区别
Q: 点击地面是如何移动的
A: track_repeat_walk(LeftMouseDown), 处理特殊情况，比如 UI，点击物品敌人等之后，再处理移动
