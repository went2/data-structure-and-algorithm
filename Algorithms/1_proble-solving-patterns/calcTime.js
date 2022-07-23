
// 性能测试装饰器
function calcTime(fn, name) {
  const start = new Date().getTime();

  return function () {
    fn.apply(this, [].slice.call(arguments, 0));
    console.log(name, 'start ', start, ' ', 'end: ', new Date().getTime());
  }
}

module.exports = { calcTime };