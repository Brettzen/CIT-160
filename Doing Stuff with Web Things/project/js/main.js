// Needs the following (in order of priority) {
//  1. Main Game Loop
// 	2. Sprite System w/ movement
// 	3. Character Stats
// 	4. Menu System
// 	5. Battle System
// 	6. Save System
// }
window.onload = function() {

	var gs = document.getElementById("gamescreen");
	newSprite = document.createElement("div");
	newSprite.style.width = "15px";
	newSprite.style.height = "30px";
	newSprite.style.position = "absolute";
	newSprite.style.top = "0";
	newSprite.style.left = "200px";
	newSprite.style.backgroundImage = "url('img/character.png')";
	
	// newSprite.style.y = "90px";
	// newSprite.setAttribute("style", "background-color: blue;");
	// newSprite.setAttribute("x", "0");
	// newSprite.setAttribute("y", "90");
	gs.appendChild(newSprite);

	window.addEventListener("keydown", checkKey, false);

	function checkKey(e) {

		e = e || window.event;

		switch(e.keyCode) {

			case 37:
				// left
				newSprite.style.backgroundPosition = "0 -96px";
				newSprite.x = parseInt(newSprite.style.left);
				newSprite.x -= 5;
				newSprite.style.left = newSprite.x + "px";
				break;
			case 38:
				// up
				newSprite.style.backgroundPosition = "0 -63px";
				newSprite.y = parseInt(newSprite.style.top);
				newSprite.y -= 5;
				newSprite.style.top = newSprite.y + "px";
				break;
			case 39:
				// right
				newSprite.style.backgroundPosition = "0 -32px";
				newSprite.x = parseInt(newSprite.style.left);
				newSprite.x += 5;
				newSprite.style.left = newSprite.x + "px";
				break;
			case 40:
				// down
				newSprite.style.backgroundPosition = "0 0";
				newSprite.y = parseInt(newSprite.style.top);
				newSprite.y += 5;
				newSprite.style.top = newSprite.y + "px";
				break;
		}
	}
}

