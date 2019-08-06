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
