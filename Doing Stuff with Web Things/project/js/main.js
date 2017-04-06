// Needs the following (in order of priority) {
//  1. Main Game Loop
// 	2. Sprite System w/ movement
// 	3. Character Stats
// 	4. Menu System
// 	5. Battle System
// 	6. Save System
// }
window.onload = function() {

	tileset = [
		{
			name: "dirt-top-mid",
			tileX: -48 * 7,
			tileY: -48 * 1,
			chipset: "img/main.png",
			passableUp: 1,
			passableRight: 1,
			passableDown: 1,
			passableLeft: 1
		},
		{
			name: "dirt-mid-mid",
			tileX: -48 * 7,
			tileY: -48 * 2,
			chipset: "img/main.png",
			passableUp: 1,
			passableRight: 1,
			passableDown: 1,
			passableLeft: 1
		},
		{
			name: "castle-top-left",
			tileX: -48 * 15,
			tileY: -48 * 10,
			chipset: "img/main.png",
			passableUp: 0,
			passableRight: 0,
			passableDown: 0,
			passableLeft: 0
		}
	];

	char = [ 
		{	
			name: "Kristaphonie",
			portrait: "img/KwisFace.png",
			sprite: "img/KwisSprite2.png",
			spriteX: 432,
			spriteY: 384,
			class: "Adventurer",
			level: "23",
			currentHP: "2500",
			maxHP: "2500",
			currentMP: "250",
			maxMP: "250"
		}, { 
			name: "Vincent",
			portrait: "img/VincentFace.png",
			sprite: "img/VincentSprite.png",
			spriteX: 0,
			spriteY: 384,
			class: "Death Mage",
			level: "49",
			currentHP: "6700",
			maxHP: "6700",
			currentMP: "540",
			maxMP: "540"
		}
	];

	impassableTiles = document.getElementsByClassName('castle-top-left');

	charImg = document.getElementById('char-img');
	charName = document.getElementById('char-name');
	charClass = document.getElementById('char-class');
	charLevel = document.getElementById('char-level');
	charHP = document.getElementById('char-hp');
	charMP = document.getElementById('char-mp');

	currTile = 0;
	currChar = 0;

	charName.innerHTML = char[currChar].name;
	charClass.innerHTML = char[currChar].class;	
	charLevel.innerHTML = "Lvl. " + char[currChar].level;	
	charHP.innerHTML = "HP: " + char[currChar].currentHP + " / " + char[currChar].maxHP;	
	charMP.innerHTML = "MP: " + char[currChar].currentMP + " / " + char[currChar].maxMP;

	charImg.innerHTML = "<img src=" + char[currChar].portrait + ">";


	//Adding things to DOM

	var gs = document.getElementById("gamescreen");

	//Adding Tiles
	function createTile(top,left){
		newTile = document.createElement("div");
		newTile.style.width = "48px";
		newTile.style.height = "48px";
		newTile.style.position = "absolute";
		newTile.className = tileset[currTile].name;
		newTile.style.backgroundPosition = tileset[currTile].tileX + "px " + tileset[currTile].tileY + "px";
		newTile.style.top = ((top*48)+400) + "px";
		newTile.style.left = (left*48) + "px";
		newTile.style.backgroundImage = "url('" + tileset[currTile].chipset + "')";
		gs.appendChild(newTile);
	}

	for(var a = 1; a <= tileset.length; a++) {
		console.log(a);
		for(var i = 0; i < (window.innerWidth/48); i++) {
			if(a == 2) {
				for(var b = 1; b < 7; b++){
					createTile(b,i);		
				}
			} else if(a == 3){
				for(var b = 1; b < 10	; b++)
					createTile(b-10, i);
			} else {
				createTile(0,i);
			}
		}
		currTile++;
	}

	//Adding Main Character
	newSprite = document.createElement("div");
	newSprite.style.width = "72px";
	newSprite.style.height = "96px";
	newSprite.style.position = "absolute";
	newSprite.style.zIndex = "20" 
	newSprite.style.backgroundPosition = char[currChar].spriteX + "px " + char[currChar].spriteY + "px";
	newSprite.style.top = "400px";
	newSprite.style.left = "400px";
	newSprite.style.backgroundImage = "url('" + char[currChar].sprite +"')";
	// newSprite.style.animation = "sprite .5s steps(3)";
	
	// newSprite.style.y = "90px";
	// newSprite.setAttribute("style", "background-color: blue;");
	// newSprite.setAttribute("x", "0");
	// newSprite.setAttribute("y", "90");

	gs.appendChild(newSprite);

	//Menu
	menu = document.getElementById("menu-window");

	// for(var i=0; i)
	newSprite.x = parseInt(newSprite.style.left);
	newSprite.y = parseInt(newSprite.style.top);
	var upSpriteCount, 
	downSpriteCount, 
	leftSpriteCount, 
	rightSpriteCount = 0;


	window.addEventListener("keydown", checkKey, false);
	function checkKey(e) {
		// var noUp, noDown, noLeft, noRight = false;

		e = e || window.event;


		if(menu.style.display == "none" || menu.style.display == ""){
			console.log(newSprite.x + " " + newSprite.y);


			switch(e.keyCode) {

				case 37:
					// left
					if(newSprite.x > 0) {
						newSprite.style.backgroundPosition = (char[currChar].spriteX - parseInt(newSprite.style.width)) + "px " +  (char[currChar].spriteY - (parseInt(newSprite.style.height)*3)) + "px";
						newSprite.x = parseInt(newSprite.style.left);
						newSprite.x -= 48;
						newSprite.style.left = newSprite.x + "px";
						if(newSprite.x <= 0) {
							newSprite.x = (window.innerWidth - parseInt(newSprite.style.width));
							newSprite.style.left = newSprite.x + "px";
						}
					}
					if(leftSpriteCount < 2) {
						newSprite.style.backgroundPositionX = parseInt(newSprite.style.backgroundPositionX) + parseInt(newSprite.style.width) + "px";
						leftSpriteCount++;
					} else {
						newSprite.style.backgroundPositionX = parseInt(newSprite.style.backgroundPositionX) - parseInt(newSprite.style.width) + "px";
						leftSpriteCount = 0; 
					}
					break;
				case 38:
					// up
					var noUp = false;
					console.log(noUp);
					for(var i=0; i < impassableTiles.length; i++) {
						if(parseInt(impassableTiles[i].style.top) == newSprite.y && (parseInt(impassableTiles[i].style.left)-32) == newSprite.x)
							noUp = true;
					}
					if(newSprite.y > 0 && noUp == false) {
						newSprite.style.backgroundPosition = (char[currChar].spriteX - parseInt(newSprite.style.width)) + "px " +  (char[currChar].spriteY - (parseInt(newSprite.style.height)*8)) + "px";
						newSprite.y = parseInt(newSprite.style.top);
						newSprite.y -= 48;
						newSprite.style.top = newSprite.y + "px";
					}
					if(upSpriteCount < 1) {
						newSprite.style.backgroundPositionX = parseInt(newSprite.style.backgroundPositionX) + parseInt(newSprite.style.width) + "px";
						upSpriteCount++;
					} else {
						newSprite.style.backgroundPositionX = parseInt(newSprite.style.backgroundPositionX) - parseInt(newSprite.style.width) + "px";
						upSpriteCount = 0; 
					}
					break;
				case 39:
					// right
					if(newSprite.x < window.innerWidth - parseInt(newSprite.style.width)) {
						newSprite.style.backgroundPosition = (char[currChar].spriteX - parseInt(newSprite.style.width)) + "px " +  (char[currChar].spriteY - (parseInt(newSprite.style.height))) + "px";
						newSprite.x = parseInt(newSprite.style.left);
						newSprite.x += 48;
						newSprite.style.left = newSprite.x + "px";
						if(newSprite.x >= (window.innerWidth - parseInt(newSprite.style.width))) {
							newSprite.x = 0;
							newSprite.style.left = newSprite.x + "px";
						}
					}
					if(rightSpriteCount < 2) {
						newSprite.style.backgroundPositionX = parseInt(newSprite.style.backgroundPositionX) + parseInt(newSprite.style.width) + "px";
						rightSpriteCount++;
					} else {
						newSprite.style.backgroundPositionX = parseInt(newSprite.style.backgroundPositionX) - parseInt(newSprite.style.width) + "px";
						rightSpriteCount = 1; 
					}
					break;
				case 40:
					// down
					if(newSprite.y < window.innerHeight - parseInt(newSprite.style.height)) {
						newSprite.style.backgroundPosition = (char[currChar].spriteX - parseInt(newSprite.style.width)) + "px " +  (char[currChar].spriteY - (parseInt(newSprite.style.height)*2)) + "px";
						newSprite.y = parseInt(newSprite.style.top);
						newSprite.y += 48;
						newSprite.style.top = newSprite.y + "px";
					}
					if(downSpriteCount < 1) {
						newSprite.style.backgroundPositionX = parseInt(newSprite.style.backgroundPositionX) + parseInt(newSprite.style.width) + "px";
						downSpriteCount++;
					} else {
						newSprite.style.backgroundPositionX = parseInt(newSprite.style.backgroundPositionX) - parseInt(newSprite.style.width) + "px";
						downSpriteCount = 0; 
					}
					break;
				case 27:
					menu.style.display = "flex";
					break;
			}

		} else if(menu.style.display == "flex"){
			switch(e.keyCode) {

				case 27:
					//esc
					menu.style.display = "none";
					break;
				case 38:
					//up
					menuScroll(e.keyCode);
				case 40: 
					//down
					menuScroll(e.keyCode);
					break;
			}

		}
	}

}

var currOpt = 1;

function menuScroll(keyPressed) {
	menuOptions = document.getElementById("options").childNodes;
	console.log(menuOptions[currOpt].innerHTML);
	menuOptions[currOpt].className = "";
	if(keyPressed == 38) {
		if(currOpt > 1) {
			currOpt --;
		}
	} else if(keyPressed == 40) {
		if(currOpt < 11) {
			currOpt += 2;
		}
	}
	menuOptions[currOpt].className = "menu-focus";
	console.log(currOpt)
}


