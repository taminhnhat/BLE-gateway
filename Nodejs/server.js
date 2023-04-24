// express module
const express = require('express')
const app = express()
const router = require('./router')
const morgan = require('morgan')
app.use(express.json())
// app.use(morgan('common'))
app.use('/', router)
const http = require("http");
app.get('/', (req, res) => {
    console.log('new request')
    res.send('done')
})

const port = 3003

// create server
const server = http.createServer(app)
server.listen(port, (err) => {
    if (err) console.log(err)
    console.log(`HTTP Server started at port ${port}`)
})

server.on('error', err => {
    console.log(err)
})