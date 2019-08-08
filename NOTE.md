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

TODO:
Q: plr.px/py WorldX, WorldY 有什么区别
