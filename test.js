const test = require('brittle')
const SystemLog = require('.')

test('log levels', async (t) => {
  const log = new SystemLog()

  await t.execution(() => log.debug('This is a debug log'))
  await t.execution(() => log.info('This is an info log'))
  await t.execution(() => log.warn('This is a warning log'))
  await t.execution(() => log.error('This is an error log'))
})

test('unicode', async (t) => {
  const log = new SystemLog()

  await t.execution(() => log.debug('Hëllø wørld'))
  await t.execution(() => log.debug('😀'))
})

test('format specifiers are not interpreted', async (t) => {
  const log = new SystemLog()

  await t.execution(() => log.debug('100%s %n %x percent'))
})
