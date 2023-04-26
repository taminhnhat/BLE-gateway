const noble = require('noble')
const BeaconScanner = require('node-beacon-scanner')

let scanner = new BeaconScanner()

scanner.onadvertisement = (ad) => {
    console.log(JSON.stringify(ad, null, '  '));
};

// Start scanning
scanner.startScan().then(() => {
    console.log('Started to scan.');
}).catch((error) => {
    console.error(error);
});