const noble = require('noble')

var serviceUUIDs = [] // default: [] => all
var allowDuplicates = false // default: false

noble.startScanning(serviceUUIDs, allowDuplicates, err => {
    if (err) console.log(err)
})
// Read the battery level of the first found peripheral exposing the Battery Level characteristic

// noble.on('stateChange', async (state) => {
//     if (state === 'poweredOn') {
//         await noble.startScanningAsync(['180f'], false);
//     }
// });

// noble.on('discover', async (peripheral) => {
//     await noble.stopScanningAsync();
//     await peripheral.connectAsync();
//     const { characteristics } = await peripheral.discoverSomeServicesAndCharacteristicsAsync(['180f'], ['2a19']);
//     const batteryLevel = (await characteristics[0].readAsync())[0];

//     console.log(`${peripheral.address} (${peripheral.advertisement.localName}): ${batteryLevel}%`);

//     await peripheral.disconnectAsync();
//     process.exit(0);
// });