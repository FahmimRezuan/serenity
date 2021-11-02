/*
 * Copyright (c) 2020, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/FlyString.h>
#include <LibJS/Forward.h>
#include <LibJS/Runtime/PropertyKey.h>

namespace JS {

#define ENUMERATE_STANDARD_PROPERTY_NAMES(P) \
    P(__proto__)                             \
    P(__defineGetter__)                      \
    P(__defineSetter__)                      \
    P(__lookupGetter__)                      \
    P(__lookupSetter__)                      \
    P(Atomics)                               \
    P(BYTES_PER_ELEMENT)                     \
    P(BigInt)                                \
    P(Boolean)                               \
    P(E)                                     \
    P(EPSILON)                               \
    P(Function)                              \
    P(Infinity)                              \
    P(Intl)                                  \
    P(JSON)                                  \
    P(LN10)                                  \
    P(LN2)                                   \
    P(LOG10E)                                \
    P(LOG2E)                                 \
    P(MAX_SAFE_INTEGER)                      \
    P(MAX_VALUE)                             \
    P(MIN_SAFE_INTEGER)                      \
    P(MIN_VALUE)                             \
    P(Math)                                  \
    P(NEGATIVE_INFINITY)                     \
    P(NaN)                                   \
    P(Now)                                   \
    P(Number)                                \
    P(PI)                                    \
    P(POSITIVE_INFINITY)                     \
    P(Proxy)                                 \
    P(Reflect)                               \
    P(RegExp)                                \
    P(SQRT1_2)                               \
    P(SQRT2)                                 \
    P(String)                                \
    P(Symbol)                                \
    P(Temporal)                              \
    P(UTC)                                   \
    P(abs)                                   \
    P(acos)                                  \
    P(acosh)                                 \
    P(add)                                   \
    P(all)                                   \
    P(allSettled)                            \
    P(anchor)                                \
    P(any)                                   \
    P(apply)                                 \
    P(arguments)                             \
    P(asIntN)                                \
    P(asUintN)                               \
    P(asin)                                  \
    P(asinh)                                 \
    P(assert)                                \
    P(assign)                                \
    P(at)                                    \
    P(atan)                                  \
    P(atan2)                                 \
    P(atanh)                                 \
    P(baseName)                              \
    P(big)                                   \
    P(bind)                                  \
    P(blank)                                 \
    P(blink)                                 \
    P(bold)                                  \
    P(buffer)                                \
    P(byteLength)                            \
    P(byteOffset)                            \
    P(calendar)                              \
    P(calendarName)                          \
    P(call)                                  \
    P(callee)                                \
    P(caller)                                \
    P(caseFirst)                             \
    P(cause)                                 \
    P(cbrt)                                  \
    P(ceil)                                  \
    P(charAt)                                \
    P(charCodeAt)                            \
    P(cleanupSome)                           \
    P(clear)                                 \
    P(clz32)                                 \
    P(codePointAt)                           \
    P(collation)                             \
    P(compactDisplay)                        \
    P(compareExchange)                       \
    P(compile)                               \
    P(concat)                                \
    P(configurable)                          \
    P(console)                               \
    P(construct)                             \
    P(constructor)                           \
    P(compare)                               \
    P(copyWithin)                            \
    P(cos)                                   \
    P(cosh)                                  \
    P(count)                                 \
    P(countReset)                            \
    P(create)                                \
    P(currency)                              \
    P(currencyDisplay)                       \
    P(currencySign)                          \
    P(dateAdd)                               \
    P(dateFromFields)                        \
    P(dateUntil)                             \
    P(day)                                   \
    P(dayOfWeek)                             \
    P(dayOfYear)                             \
    P(days)                                  \
    P(daysInMonth)                           \
    P(daysInWeek)                            \
    P(daysInYear)                            \
    P(debug)                                 \
    P(decodeURI)                             \
    P(decodeURIComponent)                    \
    P(defineProperties)                      \
    P(defineProperty)                        \
    P(deleteProperty)                        \
    P(deref)                                 \
    P(description)                           \
    P(disambiguation)                        \
    P(done)                                  \
    P(dotAll)                                \
    P(encodeURI)                             \
    P(encodeURIComponent)                    \
    P(endsWith)                              \
    P(entries)                               \
    P(enumerable)                            \
    P(epochMicroseconds)                     \
    P(epochMilliseconds)                     \
    P(epochNanoseconds)                      \
    P(epochSeconds)                          \
    P(equals)                                \
    P(era)                                   \
    P(eraYear)                               \
    P(error)                                 \
    P(errors)                                \
    P(escape)                                \
    P(eval)                                  \
    P(evaluate)                              \
    P(every)                                 \
    P(exchange)                              \
    P(exec)                                  \
    P(exp)                                   \
    P(expm1)                                 \
    P(fallback)                              \
    P(fields)                                \
    P(fill)                                  \
    P(filter)                                \
    P(finally)                               \
    P(find)                                  \
    P(findLast)                              \
    P(findLastIndex)                         \
    P(findIndex)                             \
    P(fixed)                                 \
    P(flags)                                 \
    P(flat)                                  \
    P(flatMap)                               \
    P(floor)                                 \
    P(fontcolor)                             \
    P(fontsize)                              \
    P(forEach)                               \
    P(format)                                \
    P(formatToParts)                         \
    P(fractionalSecondDigits)                \
    P(freeze)                                \
    P(from)                                  \
    P(fromCharCode)                          \
    P(fromCodePoint)                         \
    P(fromEntries)                           \
    P(fromEpochMicroseconds)                 \
    P(fromEpochMilliseconds)                 \
    P(fromEpochNanoseconds)                  \
    P(fromEpochSeconds)                      \
    P(fround)                                \
    P(gc)                                    \
    P(get)                                   \
    P(getBigInt64)                           \
    P(getBigUint64)                          \
    P(getCanonicalLocales)                   \
    P(getDate)                               \
    P(getDay)                                \
    P(getFloat32)                            \
    P(getFloat64)                            \
    P(getFullYear)                           \
    P(getHours)                              \
    P(getInstantFor)                         \
    P(getInt8)                               \
    P(getInt16)                              \
    P(getInt32)                              \
    P(getISOFields)                          \
    P(getMilliseconds)                       \
    P(getMinutes)                            \
    P(getMonth)                              \
    P(getNextTransition)                     \
    P(getOffsetNanosecondsFor)               \
    P(getOffsetStringFor)                    \
    P(getOwnPropertyDescriptor)              \
    P(getOwnPropertyDescriptors)             \
    P(getOwnPropertyNames)                   \
    P(getOwnPropertySymbols)                 \
    P(getPlainDateTimeFor)                   \
    P(getPossibleInstantsFor)                \
    P(getPreviousTransition)                 \
    P(getPrototypeOf)                        \
    P(getSeconds)                            \
    P(getTime)                               \
    P(getTimezoneOffset)                     \
    P(getUint8)                              \
    P(getUint16)                             \
    P(getUint32)                             \
    P(getUTCDate)                            \
    P(getUTCDay)                             \
    P(getUTCFullYear)                        \
    P(getUTCHours)                           \
    P(getUTCMilliseconds)                    \
    P(getUTCMinutes)                         \
    P(getUTCMonth)                           \
    P(getUTCSeconds)                         \
    P(getYear)                               \
    P(global)                                \
    P(globalThis)                            \
    P(groups)                                \
    P(has)                                   \
    P(hasIndices)                            \
    P(hasOwn)                                \
    P(hasOwnProperty)                        \
    P(hour)                                  \
    P(hourCycle)                             \
    P(hours)                                 \
    P(hypot)                                 \
    P(id)                                    \
    P(ignoreCase)                            \
    P(imul)                                  \
    P(importValue)                           \
    P(includes)                              \
    P(index)                                 \
    P(indexOf)                               \
    P(indices)                               \
    P(info)                                  \
    P(inLeapYear)                            \
    P(input)                                 \
    P(instant)                               \
    P(is)                                    \
    P(isArray)                               \
    P(isExtensible)                          \
    P(isFinite)                              \
    P(isFrozen)                              \
    P(isInteger)                             \
    P(isLockFree)                            \
    P(isNaN)                                 \
    P(isPrototypeOf)                         \
    P(isSafeInteger)                         \
    P(isSealed)                              \
    P(isView)                                \
    P(isoDay)                                \
    P(isoHour)                               \
    P(isoMicrosecond)                        \
    P(isoMillisecond)                        \
    P(isoMinute)                             \
    P(isoMonth)                              \
    P(isoNanosecond)                         \
    P(isoSecond)                             \
    P(isoYear)                               \
    P(italics)                               \
    P(join)                                  \
    P(keyFor)                                \
    P(keys)                                  \
    P(language)                              \
    P(largestUnit)                           \
    P(lastIndex)                             \
    P(lastIndexOf)                           \
    P(length)                                \
    P(link)                                  \
    P(load)                                  \
    P(locale)                                \
    P(localeCompare)                         \
    P(localeMatcher)                         \
    P(log)                                   \
    P(log1p)                                 \
    P(log2)                                  \
    P(log10)                                 \
    P(map)                                   \
    P(max)                                   \
    P(maximize)                              \
    P(mergeFields)                           \
    P(message)                               \
    P(microsecond)                           \
    P(microseconds)                          \
    P(millisecond)                           \
    P(milliseconds)                          \
    P(min)                                   \
    P(minimize)                              \
    P(maximumFractionDigits)                 \
    P(maximumSignificantDigits)              \
    P(minimumFractionDigits)                 \
    P(minimumIntegerDigits)                  \
    P(minimumSignificantDigits)              \
    P(minute)                                \
    P(minutes)                               \
    P(month)                                 \
    P(monthCode)                             \
    P(monthDayFromFields)                    \
    P(months)                                \
    P(monthsInYear)                          \
    P(multiline)                             \
    P(name)                                  \
    P(nanosecond)                            \
    P(nanoseconds)                           \
    P(negated)                               \
    P(next)                                  \
    P(notation)                              \
    P(now)                                   \
    P(numberingSystem)                       \
    P(numeric)                               \
    P(of)                                    \
    P(offset)                                \
    P(offsetNanoseconds)                     \
    P(overflow)                              \
    P(ownKeys)                               \
    P(padEnd)                                \
    P(padStart)                              \
    P(parse)                                 \
    P(parseFloat)                            \
    P(parseInt)                              \
    P(plainDate)                             \
    P(plainDateISO)                          \
    P(plainDateTime)                         \
    P(plainDateTimeISO)                      \
    P(plainTime)                             \
    P(plainTimeISO)                          \
    P(pop)                                   \
    P(pow)                                   \
    P(preventExtensions)                     \
    P(propertyIsEnumerable)                  \
    P(prototype)                             \
    P(proxy)                                 \
    P(push)                                  \
    P(race)                                  \
    P(random)                                \
    P(raw)                                   \
    P(reason)                                \
    P(reduce)                                \
    P(reduceRight)                           \
    P(region)                                \
    P(reject)                                \
    P(repeat)                                \
    P(resolve)                               \
    P(resolvedOptions)                       \
    P(reverse)                               \
    P(revocable)                             \
    P(revoke)                                \
    P(round)                                 \
    P(roundingIncrement)                     \
    P(roundingMode)                          \
    P(script)                                \
    P(seal)                                  \
    P(second)                                \
    P(seconds)                               \
    P(set)                                   \
    P(setBigInt64)                           \
    P(setBigUint64)                          \
    P(setDate)                               \
    P(setFloat32)                            \
    P(setFloat64)                            \
    P(setFullYear)                           \
    P(setHours)                              \
    P(setInt8)                               \
    P(setInt16)                              \
    P(setInt32)                              \
    P(setMilliseconds)                       \
    P(setMinutes)                            \
    P(setMonth)                              \
    P(setPrototypeOf)                        \
    P(setSeconds)                            \
    P(setTime)                               \
    P(setUint8)                              \
    P(setUint16)                             \
    P(setUint32)                             \
    P(setUTCDate)                            \
    P(setUTCFullYear)                        \
    P(setUTCHours)                           \
    P(setUTCMilliseconds)                    \
    P(setUTCMinutes)                         \
    P(setUTCMonth)                           \
    P(setUTCSeconds)                         \
    P(setYear)                               \
    P(shift)                                 \
    P(sign)                                  \
    P(signDisplay)                           \
    P(sin)                                   \
    P(since)                                 \
    P(sinh)                                  \
    P(size)                                  \
    P(slice)                                 \
    P(small)                                 \
    P(smallestUnit)                          \
    P(some)                                  \
    P(sort)                                  \
    P(source)                                \
    P(splice)                                \
    P(sqrt)                                  \
    P(startsWith)                            \
    P(status)                                \
    P(sticky)                                \
    P(store)                                 \
    P(strike)                                \
    P(stringify)                             \
    P(style)                                 \
    P(sub)                                   \
    P(subarray)                              \
    P(substr)                                \
    P(substring)                             \
    P(subtract)                              \
    P(sup)                                   \
    P(supportedLocalesOf)                    \
    P(tan)                                   \
    P(tanh)                                  \
    P(test)                                  \
    P(then)                                  \
    P(timeZone)                              \
    P(toDateString)                          \
    P(toFixed)                               \
    P(toGMTString)                           \
    P(toInstant)                             \
    P(toISOString)                           \
    P(toJSON)                                \
    P(toLocaleDateString)                    \
    P(toLocaleLowerCase)                     \
    P(toLocaleString)                        \
    P(toLocaleTimeString)                    \
    P(toLocaleUpperCase)                     \
    P(toLowerCase)                           \
    P(toPlainDate)                           \
    P(toPlainDateTime)                       \
    P(toPlainMonthDay)                       \
    P(toPlainTime)                           \
    P(toPlainYearMonth)                      \
    P(toString)                              \
    P(toTemporalInstant)                     \
    P(toTimeString)                          \
    P(toUpperCase)                           \
    P(toUTCString)                           \
    P(toZonedDateTime)                       \
    P(toZonedDateTimeISO)                    \
    P(trace)                                 \
    P(trim)                                  \
    P(trimEnd)                               \
    P(trimLeft)                              \
    P(trimRight)                             \
    P(trimStart)                             \
    P(trunc)                                 \
    P(type)                                  \
    P(undefined)                             \
    P(unescape)                              \
    P(unicode)                               \
    P(unit)                                  \
    P(unitDisplay)                           \
    P(until)                                 \
    P(unregister)                            \
    P(unshift)                               \
    P(useGrouping)                           \
    P(value)                                 \
    P(valueOf)                               \
    P(values)                                \
    P(warn)                                  \
    P(weekOfYear)                            \
    P(weeks)                                 \
    P(with)                                  \
    P(withCalendar)                          \
    P(withPlainDate)                         \
    P(withPlainTime)                         \
    P(writable)                              \
    P(year)                                  \
    P(yearMonthFromFields)                   \
    P(years)                                 \
    P(zonedDateTime)                         \
    P(zonedDateTimeISO)

struct CommonPropertyNames {
    PropertyKey and_ { "and", PropertyKey::StringMayBeNumber::No };
    PropertyKey catch_ { "catch", PropertyKey::StringMayBeNumber::No };
    PropertyKey delete_ { "delete", PropertyKey::StringMayBeNumber::No };
    PropertyKey for_ { "for", PropertyKey::StringMayBeNumber::No };
    PropertyKey or_ { "or", PropertyKey::StringMayBeNumber::No };
    PropertyKey register_ { "register", PropertyKey::StringMayBeNumber::No };
    PropertyKey return_ { "return", PropertyKey::StringMayBeNumber::No };
    PropertyKey throw_ { "throw", PropertyKey::StringMayBeNumber::No };
    PropertyKey xor_ { "xor", PropertyKey::StringMayBeNumber::No };
#define __ENUMERATE(x) PropertyKey x { #x, PropertyKey::StringMayBeNumber::No };
    ENUMERATE_STANDARD_PROPERTY_NAMES(__ENUMERATE)
#undef __ENUMERATE
#define __JS_ENUMERATE(x, a, b, c, t) PropertyKey x { #x, PropertyKey::StringMayBeNumber::No };
    JS_ENUMERATE_BUILTIN_TYPES
#undef __JS_ENUMERATE
#define __JS_ENUMERATE(x, a, b, c) PropertyKey x { #x, PropertyKey::StringMayBeNumber::No };
    JS_ENUMERATE_INTL_OBJECTS
#undef __JS_ENUMERATE
#define __JS_ENUMERATE(x, a, b, c) PropertyKey x { #x, PropertyKey::StringMayBeNumber::No };
    JS_ENUMERATE_TEMPORAL_OBJECTS
#undef __JS_ENUMERATE
#define __JS_ENUMERATE(x, a) PropertyKey x { #x, PropertyKey::StringMayBeNumber::No };
    JS_ENUMERATE_WELL_KNOWN_SYMBOLS
#undef __JS_ENUMERATE
};

}
