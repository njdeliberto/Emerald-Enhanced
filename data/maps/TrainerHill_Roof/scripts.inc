TrainerHill_Roof_MapScripts:: @ 8268FA7
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_OnFrame
	.byte 0

TrainerHill_Roof_EventScript_Owner:: @ 8268FB2
	goto_if_set FLAG_TEMP_B, ryu_end
	trainerhill_settrainerflags
	lock
	setflag FLAG_TEMP_B
	faceplayer
	specialvar VAR_RESULT, RyuGetTrainerHillReward
	playfanfare MUS_FANFA1
	giveitem VAR_RESULT
	msgbox TrainerHill_Roof_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
	waitfanfare
	waitmessage
	msgbox TrainerHill_Roof_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
	release
	end

