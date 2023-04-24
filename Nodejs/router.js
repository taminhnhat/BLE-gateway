const express = require('express')
const router = express.Router()

router.get('/ble-scan', (req, res) => {
    res.status(200).json({
        status: 'success'
    })
})

router.post('/ble-scan', (req, res) => {
    console.log(req.body.message)
    res.status(200).json({
        status: 'success'
    })
})


module.exports = router
