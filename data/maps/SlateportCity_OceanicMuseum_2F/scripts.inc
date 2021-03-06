SlateportCity_OceanicMuseum_2F_MapScripts:: @ 820BAFF
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern:: @ 820BB00
	lock
	faceplayer
	goto_if_unset FLAG_RECOVERED_DEVON_GOODS, OM_NoQuest
	playse SE_BIDORO
	waitse
	goto_if_set FLAG_DEVON_GOODS_STOLEN, OM_NoQuest
	playse SE_EXPMAX
	waitse
	goto_if_set FLAG_RYU_PLAYER_HELPING_AQUA, OM_AlreadyWorkingAqua
	goto_if_set FLAG_RYU_PLAYER_HELPING_DEVON, OM_Normal
	playse SE_PIN
	waitse
	goto OM_NoQuest

OM_Normal::
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_AQA_0, 1
	addobject 3
	applymovement 3, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject 4
	applymovement 4, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement 3, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement 4, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	compare VAR_FACING, 1
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	compare VAR_FACING, 4
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox OM_AquaEnters2f, MSGBOX_DEFAULT
	compare VAR_FACING, 4
	call_if_ne SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox OM_SternSuprise, MSGBOX_DEFAULT
	msgbox OM_AquaEnters, MSGBOX_DEFAULT
	closemessage
	applymovement 4, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	compare VAR_FACING, 1
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	compare VAR_FACING, 3
	call_if_eq SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_GRUNT_14, OM_Aqua1defeated
	msgbox SlateportCity_OceanicMuseum_2F_Text_20BEFA, MSGBOX_DEFAULT
	closemessage
	applymovement 4, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement 3, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox OM_Aqua2intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_15, OM_Aqua2defeated
	applymovement 3, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement 3, Common_Movement_FaceUp
	applymovement 4, Common_Movement_FaceUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject 2
	applymovement 2, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement 4, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox OM_ArchieEnters, MSGBOX_DEFAULT
	closemessage
	applymovement 2, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox OM_ArchieIntro, MSGBOX_DEFAULT
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, OM_SternNormal
	msgbox OM_ArchieQuery, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne OM_Declined
	msgbox OM_ArchieConfirmed MSGBOX_DEFAULT
	call RyuGivePokenav
	setflag FLAG_RYU_PLAYER_ARCHIE_ACQ
	setflag FLAG_RYU_PLAYER_HELPING_AQUA
	clearflag FLAG_RYU_PLAYER_HELPING_DEVON
	setflag FLAG_RYU_DS_SHELLY_ACQ
	removeitem ITEM_DEVON_GOODS, 1
	msgbox OM_ArchieLeaving MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen 1
	removeobject 2
	removeobject 3
	removeobject 4
	fadescreen 0
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	special HealPlayerParty
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	release
	end
	
OM_SternNormal::
	goto OM_Declined

OM_Declined::
	MSGBOX OM_ArchieDeclinedmsg MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen 1
	removeobject 2
	removeobject 3
	removeobject 4
	fadescreen 0
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	removeitem ITEM_DEVON_GOODS, 1
	setvar VAR_0x8004, 269
	closemessage
	fadescreen 1
	special HealPlayerParty
	removeobject 1
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	setflag FLAG_DELIVERED_DEVON_GOODS
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	setflag FLAG_RYU_PLAYER_HELPING_DEVON
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	fadescreen 0
	release
	end
	
OM_NoQuest::
	msgbox OM_NoQuestMsg MSGBOX_DEFAULT
	release
	end
	
OM_NoQuestMsg:
	.string "Stern: Hi.\nI'm waiting on an important delivery.\pPlease stop bothering me.$"
	
OM_AlreadyWorkingAqua:
	msgbox OM_Stern_AlreadyMember MSGBOX_DEFAULT
	release
	end
	
OM_Stern_AlreadyMember:
	.string "You dirty thieves.\nWhy don't you go back to\lLilycove and leave us alone...$"


SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch:: @ 820BC8C
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts:: @ 820BC92
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts:: @ 820BC9D
	applymovement 1, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth:: @ 820BCA8
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest:: @ 820BCB3
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth: @ 820BCBE
	walk_left
	walk_down
	walk_in_place_fastest_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest: @ 820BCC2
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_fastest_left
	step_end

@ Unused
SlateportCity_OceanicMuseum_2F_Movement_20BCC8: @ 820BCC8
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer: @ 820BCD6
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter: @ 820BCD8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle: @ 820BCE2
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter: @ 820BCE4
	walk_down
	walk_right
	walk_in_place_fastest_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach: @ 820BCE8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated: @ 820BCEF
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter: @ 820BCF3
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach: @ 820BCF5
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie: @ 820BCFE
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_fastest_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1:: @ 820BD0A
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2:: @ 820BD13
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment:: @ 820BD1C
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel:: @ 820BD25
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay:: @ 820BD2E
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay:: @ 820BD37
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica:: @ 820BD40
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica:: @ 820BD49
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica:: @ 820BD52
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica:: @ 820BD5B
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1:: @ 820BD64
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2:: @ 820BD6D
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3:: @ 820BD76
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

OM_AquaEnters2f: @ 820BE40
	.string "Hehehe, hold it!\n"
	.string "We'll take those parts!$"

OM_SternSuprise: @ 820BE69
	.string "CAPT. STERN: Wh-what?\n"
	.string "Who are you people?$"

OM_AquaEnters: @ 820BE93
	.string "We're Team Aqua!\p"
	.string "Our BOSS wants those parts!\n"
	.string "Shut your yap and fork them over!$"

OM_Aqua1defeated: @ 820BEE2
	.string "Awaaaah!\n"
	.string "A kid beat me!$"

SlateportCity_OceanicMuseum_2F_Text_20BEFA: @ 820BEFA
	.string "Oh, man, what a disaster…\n"
	.string "The BOSS is going to be furious…$"

OM_Aqua2intro: @ 820BF35
	.string "Humph, sniveling wimp!\n"
	.string "Let me take care of this!$"

OM_Aqua2defeated: @ 820BF66
	.string "What?!\n"
	.string "I lost, too!$"

SlateportCity_OceanicMuseum_2F_Text_20BF7A: @ 820BF7A
	.string "Now what? If we don't get the parts,\n"
	.string "we're in for it!\p"
	.string "Arrgh, I didn't count on being meddled\n"
	.string "with by some meddling kid!$"

OM_ArchieEnters: @ 820BFF2
	.string "I came to see what was taking so\n"
	.string "long to snatch some parts, and you\l"
	.string "simps are held up by a mere child?$"

OM_ArchieIntro: @ 820C059
	.string "We are Team Aqua,\n"
	.string "and we love the sea!\p"
	.string "And I am Team Aqua's Leader,\n"
	.string "ARCHIE!\p"
	.string "What makes you interfere with us?\p"
	.string "…No! You can't be!\n"
	.string "You're not one of Team Magma?\p"
	.string "Wait, that can't be right.\n"
	.string "You're not dressed for the part.\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

OM_ArchieConfirmed:
	.string "Excellent choice. I think your\ntalents will be better harnessed\lwithin our organization. Report to\l"
	.string "Shelly in our corporate office.\lThese goods were intended to go\lthere, anyways.$"
	
OM_ArchieLeave:
	.string "Aqua! MOVE OUT!$"

OM_ArchieLeaving:
	.string "Tell Devon we send our regards!$"

OM_ArchieQuery:
	.string "Ah, I see, you thought you were\njust doing the right thing.\pRight, well It's clear that you're a cut\nabove my soldiers.\p"
	.string "How'd you like to work for\n"
	.string "Aqua instead? There's money in it!$"

OM_SternBeg:
	.string "Capt. Stern: Oh you're giving it\nto me?$"
	
OM_MessWithStern:
	.string "{PLAYER}: Yeah, sure. Here you go.\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}({PLAYER} pretends to hold the\n package out for Stern then quickly\l rips it away.\p"
	.string " Stern looks crestfallen and\n angry)$"

OM_SternDeclinedMsg:
	.string "{PLAYER}: No, I don't think so.\n"
	.string "I'd rather get the money.\p"
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}({PLAYER} decided to join team Aqua.)$"
	
OM_ArchieEntertained:
	.string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Archie: Wahahaha! We're going to\lget along just fine, {PLAYER}.$" 

OM_ArchieDeclinedmsg:
	.string "Pokémon, people… All life depends on\n"
	.string "the sea.\p"
	.string "So, Team Aqua is dedicated to\n"
	.string "the expansion of the sea.\p"
	.string "Don't you agree? What we are doing\n"
	.string "is a magnificent undertaking.\p"
	.string "Ah, fine…\n"
	.string "You're still too young to understand\l"
	.string "our noble objective.\p"
	.string "But, I warn you, don't even consider\n"
	.string "interfering with our plans again.\p"
	.string "The consequences will cost you\n"
	.string "dearly!\p"
	.string "And don't you forget it!$"

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts: @ 820BD8D
	.string "Yes? If you're looking for STERN,\n"
	.string "that would be me.\p"
	.string "Ah! Those must be the parts I ordered\n"
	.string "from MR. STONE of DEVON.\p"
	.string "Thank you! That's great!\n"
	.string "We can prepare for our expedition now.$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts: @ 820BE40
	.string "Hehehe, hold it!\n"
	.string "We'll take those parts!$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou: @ 820BE69
	.string "CAPT. STERN: Wh-what?\n"
	.string "Who are you people?$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua: @ 820BE93
	.string "We're Team Aqua!\p"
	.string "Our BOSS wants those parts!\n"
	.string "Shut your yap and fork them over!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat: @ 820BEE2
	.string "Awaaaah!\n"
	.string "A kid beat me!$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious: @ 820BEFA
	.string "Oh, man, what a disaster…\n"
	.string "The BOSS is going to be furious…$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis: @ 820BF35
	.string "Humph, sniveling wimp!\n"
	.string "Let me take care of this!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat: @ 820BF66
	.string "What?!\n"
	.string "I lost, too!$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid: @ 820BF7A
	.string "Now what? If we don't get the parts,\n"
	.string "we're in for it!\p"
	.string "Arrgh, I didn't count on being meddled\n"
	.string "with by some meddling kid!$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong: @ 820BFF2
	.string "I came to see what was taking so\n"
	.string "long to snatch some parts, and you\l"
	.string "simps are held up by a mere child?$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning: @ 820C059
	.string "We are Team Aqua,\n"
	.string "and we love the sea!\p"
	.string "And I am Team Aqua's leader,\n"
	.string "ARCHIE!\p"
	.string "What makes you interfere with us?\p"
	.string "…No! You can't be!\n"
	.string "You're not one of Team Magma?\p"
	.string "Wait, that can't be right.\n"
	.string "You're not dressed for the part.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Pokémon, people… All life depends on\n"
	.string "the sea.\p"
	.string "So, Team Aqua is dedicated to\n"
	.string "the expansion of the sea.\p"
	.string "Don't you agree? What we are doing\n"
	.string "is a magnificent undertaking.\p"
	.string "Ah, fine…\n"
	.string "You're still too young to understand\l"
	.string "our noble objective.\p"
	.string "But, I warn you, don't even consider\n"
	.string "interfering with our plans again.\p"
	.string "The consequences will cost you\n"
	.string "dearly!\p"
	.string "And don't you forget it!$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs: @ 820C2BE
	.string "CAPT. STERN: You're…\n"
	.string "Ah, okay, you're {PLAYER}…\p"
	.string "Anyway, that was a tense situation!\n"
	.string "Thank you for saving us!\p"
	.string "Oh, yes, I almost forgot that you\n"
	.string "even brought the parts from DEVON!$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo: @ 820C36C
	.string "CAPT. STERN: Whoops!\n"
	.string "There's no time to lose!\p"
	.string "We have to set out on our ocean-floor\n"
	.string "expedition really soon.\p"
	.string "Thanks again, but now I've got\n"
	.string "to go!\p"
	.string "Feel free to wander around and check\n"
	.string "out our facilities, though.$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip: @ 820C43F
	.string "I saw a model of a ship here.\p"
	.string "It reminded me of the ABANDONED SHIP\n"
	.string "near DEWFORD TOWN…$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum: @ 820C495
	.string "Don't you dare run around inside\n"
	.string "the MUSEUM!$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine: @ 820C4C2
	.string "Wow, the submarine's awesome!\n"
	.string "I want to go for a ride!$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1: @ 820C4F9
	.string "“WATER QUALITY SAMPLE 1,” the\n"
	.string "label says.\p"
	.string "The sea is all connected, but the\n"
	.string "water seems to differ by region.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2: @ 820C566
	.string "“WATER QUALITY SAMPLE 2,” the\n"
	.string "label says.\p"
	.string "Does the saltiness of seawater differ\n"
	.string "by region, too?$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment: @ 820C5C6
	.string "A rubber ball is expanding and\n"
	.string "shrinking.\p"
	.string "“In the sea, the weight of water itself\n"
	.string "exerts pressure.\p"
	.string "“In shallow water, the pressure is not\n"
	.string "very heavy.\p"
	.string "“However, in extremely deep water,\n"
	.string "the pressure can reach even tens of\l"
	.string "thousands of tons on a small area.”$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel: @ 820C6C7
	.string "“MODEL OF Hoenn REGION”\p"
	.string "It's a miniature diorama of the\n"
	.string "Hoenn region.\p"
	.string "Where is LITTLEROOT TOWN on this?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay: @ 820C72F
	.string "It's a display on the flow of seawater.\p"
	.string "“Near the bottom of the sea, water\n"
	.string "flows due to differences in such\l"
	.string "factors as temperature and salinity.”$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay: @ 820C7C1
	.string "It's a display on the flow of seawater.\p"
	.string "“Toward the surface, seawater flows\n"
	.string "as currents driven by the winds.”$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica: @ 820C82F
	.string "“THE FERRY S.S. TIDAL\p"
	.string "“A scale replica of the ship under\n"
	.string "construction at STERN's SHIPYARD.”$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica: @ 820C88B
	.string "“SUBMARINE EXPLORER 1\p"
	.string "“A replica of the high-performance\n"
	.string "ocean floor exploration submarine.”$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica: @ 820C8E8
	.string "“SUBMERSIBLE POD\p"
	.string "“A replica of a compact, unmanned\n"
	.string "pod for seafloor exploration.”$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica: @ 820C93A
	.string "“S.S. ANNE\p"
	.string "“A replica of the luxury liner that\n"
	.string "circles the globe.”$"

