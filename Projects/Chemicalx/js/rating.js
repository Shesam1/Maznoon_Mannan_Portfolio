
function likeCount() {
  likedIt();
  counter();
}
function dislikeCount (){
  dislikedIt();
  counter2();
}

function likedIt () {
  var outcome;
  outcome = 'You have liked this recipe. <br /> Try our <a href="../html/carrotcake.html" class="suggest">Carrot Cake</a> recipe next.';
  document.getElementById("replace").innerHTML= outcome;
}
function counter() {
    if(typeof(Storage) !== "undefined") {
        if (localStorage.clickcount) {
            localStorage.clickcount = Number(localStorage.clickcount)+1;
        } else {
            localStorage.clickcount = 1;
        }
        document.getElementById("number").innerHTML = "This recipe has been liked " + localStorage.clickcount + " time(s).";
    } else {
        document.getElementById("number").innerHTML = "Web storage not supported by your browser.";
    }
}

function dislikedIt () {
  var outcome;
  outcome = 'You have disliked this recipe. <br /> Try our <a href="../html/brownies.html" class="suggest"> Chocolate Brownies</a> recipe instead.';
  document.getElementById("replace").innerHTML= outcome;
}
function counter2() {
    if(typeof(Storage) !== "undefined") {
        if (localStorage.clickcount) {
            localStorage.clickcount = Number(localStorage.clickcount)+1;
        } else {
            localStorage.clickcount = 1;
        }
        document.getElementById("number").innerHTML = "This recipe has been disliked " + localStorage.clickcount + " time(s).";
    } else {
        document.getElementById("number").innerHTML = "Web storage not supported by your browser.";
    }
}

//click count function learned through w3schools
