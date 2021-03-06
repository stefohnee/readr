% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/write_lines.R
\name{write_file}
\alias{write_file}
\title{Write a string to a file}
\usage{
write_file(x, path, append = FALSE)
}
\arguments{
\item{x}{A data frame to write to disk}

\item{path}{Path to write to.}

\item{append}{If \code{FALSE}, will overwrite existing file. If \code{TRUE},
will append to existing file. In both cases, if file does not exist a new
file is created.}
}
\value{
The input \code{x}, invisibly.
}
\description{
\code{write_file} takes a single string, or a raw vector,
and writes it exactly as is.
}
\examples{
tmp <- tempfile()

x <- format_csv(mtcars[1:6, ])
write_file(x, tmp)
identical(x, read_file(tmp))

read_lines(x)
}

