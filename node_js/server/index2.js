const express = require("express");
const app = express();
const server = require("http").Server(app);
//const SocketIo = require("socket.io");

//const server = http.createServer(app);
const io = require("socket.io")(server); //Configuracion web socket
app.use(express.static(__dirname + "/public"));
server.listen(3000, () => {
  console.log("puerto open");
});

app.use("/login", require(__dirname + "/public/routes/prueba"));
app.get("/prueba", (req, res) => {
  res.sendFile(__dirname + "/public/temperatura.html");
});

//Serial configuracion
const SerialPort = require("serialport");
const Readline = SerialPort.parsers.Readline;

const port = new SerialPort("COM10", {
  baudRate: 9600
});

const parser = port.pipe(new Readline({ delimiter: "\r\n" }));
parser.on("open", function () {
  console.log("Puerto abiertaaaaaao");
});
parser.on("data", function (data) {
  console.log(data);
  io.emit("temp", data);
});
parser.on("error", function (err) {
  console.log(err);
});
