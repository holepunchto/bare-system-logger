# bare-system-logger

System logger for Bare.

## Usage

```js
const SystemLog = require('bare-system-logger')

const log = new SystemLog()

log.info('Hello %s', 'world!')
```

## API

See the [`bare-system-logger` reference](https://docs.pears.com/reference/bare/modules/bare-system-logger).

## Threat model

`bare-system-logger` is one of the addons Bare compiles into its binary, so it inherits [Bare's threat model](https://github.com/holepunchto/bare/blob/main/docs/threat-model.md). See [`docs/threat-model.md`](docs/threat-model.md) for where this addon sits in it.

## License

Apache-2.0
