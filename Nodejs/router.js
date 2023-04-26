const express = require('express')
const router = express.Router()
const controller = require('./controller')

router.get('/ble-scan', (req, res) => {
    res.status(200).json({
        status: 'success'
    })
})

router.post('/ble-scan', controller.newScan())

module.exports = router
