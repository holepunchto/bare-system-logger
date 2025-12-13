const Log = require('bare-logger')
const binding = require('./binding')

module.exports = class SystemLog extends Log {
  constructor() {
    super({ colors: false })
  }

  debug(...data) {
    binding.debug(this.format(...data))
  }

  info(...data) {
    binding.info(this.format(...data))
  }

  warn(...data) {
    binding.warn(this.format(...data))
  }

  error(...data) {
    binding.error(this.format(...data))
  }

  fatal(...data) {
    binding.fatal(this.format(...data))
  }
}
