document.addEventListener("DOMContentLoaded", () => {
  const fileNameBox = document.getElementById("fileName");

  document.getElementById("btn1").addEventListener("click", () => {
    alert("Button 1 clicked!");
  });

  document.getElementById("btn2").addEventListener("click", () => {
    alert("Button 2 clicked!");
  });

  document.getElementById("btn3").addEventListener("click", async () => {
    // call the Go backend
    // using the bound function named "PickFile"
    const path = await window.PickFile();
    if (path) {
      fileNameBox.value = path;
    }
  });
});
