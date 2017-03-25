'use strict';
var canvas = document.getElementById("canvas");
var ctx = canvas.getContext("2d");


const SCALE_FACTOR = 1;
const MAX_DEPTH = 10;
const ANGLE = Math.PI/2;
const LENGTHSCALE = 0.75;
const NUMBRANCHES = 4;


function drawLine(x1, y1, x2, y2) {
  ctx.beginPath();
  ctx.moveTo(x1 * SCALE_FACTOR, y1 * SCALE_FACTOR);
  ctx.lineTo(x2 * SCALE_FACTOR, y2 * SCALE_FACTOR);
  ctx.stroke();
}

drawLine(400, 800, 400, 500)
tree(1, 400, 500, 3*Math.PI/2)

function tree(depth, xstart, ystart, angle) {
	// start at left-most branch
	angle -= ANGLE/2;
	//ctx.strokeRect(xstart,ystart, 10,10);
	// number of branches at node determined by for loop
	for(var i = 0; i < NUMBRANCHES; i++) {
		if(Math.random() < 1-(depth/MAX_DEPTH)) {
			// draw a line (need to know: start and end and width)
			var length = 100 / (LENGTHSCALE * depth);
			var xend = Math.cos(angle)*length + xstart;
			var yend = Math.sin(angle)*length + ystart;
			drawLine(xstart, ystart, xend, yend);
			
			// if we want to recurse
			if(depth < MAX_DEPTH) {
				if(depth > 4){
					ctx.strokeRect(xend, yend, 5, 5);
				}
				tree(depth+1, xend, yend, angle);
			} else {
				// put in a leaf

			}
		}
		// update to new angle
		angle += ANGLE / (NUMBRANCHES-1);
	}
	
	
}