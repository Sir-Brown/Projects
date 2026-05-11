function myFunction() {
  var x = document.getElementById("navigation");
  if (x.className === "nav") {
    x.className += " responsive";
  } else {
    x.className = "nav";
  }
}