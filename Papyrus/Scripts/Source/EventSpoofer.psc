Scriptname EventSpoofer
{ Spoof events with SKSE. Events are dispatched the same way Skyrim dispatches them (ex: OnHit gets sent to source's actor script,
    ref aliases's scripts and scripts of the active magic effects on that actor. )
    All spoof functions are defined as SpoofEVENTNAME(source, args...), where source is the Form receiving the spoofed event
    and args are the arguments of that event

    Ex: SpoofOnVampireFeed(Game.GetPlayer(), NiryaRef) will dispatch the "OnVampireFeed" event to the player,
    with the single argument "akTarget" being Nirya, tricking scripts into thinking the player just fed on Nirya
}

Function SpoofOnActivate(ObjectReference source, ObjectReference akActivator) global native

Function SpoofOnVampireFeed(Actor source, Actor akTarget) global native