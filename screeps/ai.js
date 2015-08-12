
var hcnt = 0;
var harvester =  function (creep) {

	if(creep.carry.energy < creep.carryCapacity) {
		var sources = creep.room.find(FIND_SOURCES);
		if(creep.target == undefined)
		{
		    creep.target = sources[hcnt / 3];
    		hcnt++;
    		hcnt %= (sources.length * 3);
		}
		creep.moveTo(creep.target);
        creep.harvest(creep.target);
	}
	else {
		creep.moveTo(Game.spawns.Spawn1);
		creep.transferEnergy(Game.spawns.Spawn1)
	}
}


var createHarvester = function(name)
{
    var runid = Game.spawns.Spawn1.createCreep( [WORK, CARRY, MOVE], name );
    if(runid >= 0) { Memory.creeps[runid].role  = 'harvester'; console.log("Create Harvester " + runid); }
    return runid;
}

var createBuilder = function(name)
{
    var runid = Game.spawns.Spawn1.createCreep( [WORK, WORK, CARRY, MOVE], name );
    if(runid >= 0) Memory.creeps[runid].role  = 'builder';
    return runid;
}

var createGuard = function(name)
{
    var runid = Game.spawns.Spawn1.createCreep( [MOVE, ATTACK, MOVE], name );
    if(runid >= 0) Memory.creeps[runid].role  = 'guard';
    return runid;
}

var cnt_harvester = 0;
var cnt_builder = 0;
var cnt_guard = 0;
for(var name in Game.creeps) {

	var creep = Game.creeps[name];

	if(creep.memory.role == 'harvester') {
		harvester(creep);
		cnt_harvester++;
	}

	if(creep.memory.role == 'builder') {
	    cnt_builder++;
		if(creep.carry.energy == 0) {
			creep.moveTo(Game.spawns.Spawn1);
			Game.spawns.Spawn1.transferEnergy(creep);
		}
		else {
			var targets = creep.room.find(FIND_SOURCES);
			if(targets.length) {
				creep.moveTo(targets[0]);
				creep.build(targets[0]);
			}
		}
	}
	if(creep.memory.role == 'guard') {
	    cnt_guard++;
    	var target = creep.pos.findClosest(FIND_HOSTILE_CREEPS);
    	if(target) {
    	    if(Math.abs(target.pos.x - creep.pos.x) + Math.abs(target.pos.y - creep.pos.y) <= 20)
    	    {
    	        creep.moveTo(target);
        		creep.attack(target);  
    	    }
	    }
    }
}




for(var base = 1; base <= 10; base++)
{
    var flag = false;
    if(cnt_harvester < base)
    {
        var id = Math.random();
        createHarvester(id.toString());
        flag = true;
    }
    if(flag) break;
    if(cnt_guard < 1 * base)
    {
        var id = Math.random();
        createGuard(id.toString());
        flag = true;
    }
    if(flag) break;
    /*
    if(base + cnt_builder < 2)
    {
        var id = Math.random();
        createBuilder(id.toString());
        flag = true;
    }
    */
    
}

